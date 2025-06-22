typedef struct PTMF {
	long	this_delta;
	long	vtbl_offset;
	union {
		void	*func_addr;
		long	ventry_offset;
	}	func_data;
} PTMF;

// const PTMF __ptmf_null = { 0, 0, 0 };

asm long __ptmf_test(register PTMF *ptmf) {
    #ifdef __MWERKS__ // clang-format off
        nofralloc
        lwz		r5,PTMF.this_delta(r3)
        lwz		r6,PTMF.vtbl_offset(r3)
        lwz		r7,PTMF.func_data(r3)
        li		r3,1
        cmpwi	cr0,r5,0
        cmpwi	cr6,r6,0
        cmpwi	cr7,r7,0
        bnelr	cr0
        bnelr	cr6
        bnelr	cr7
        li		r3,0
        blr
    #endif // clang-format on
}

asm void __ptmf_scall() {
    #ifdef __MWERKS__ // clang-format off
        nofralloc
        lwz		r0,PTMF.this_delta(r12)
        lwz		r11,PTMF.vtbl_offset(r12)
        lwz		r12,PTMF.func_data(r12)
        add		r3,r3,r0
        cmpwi	cr0,r11,0
        blt		cr0,@1
        lwzx	r12,r3,r12
        lwzx	r12,r12,r11
    @1  mtctr	r12
        bctr
    #endif // clang-format on
}
