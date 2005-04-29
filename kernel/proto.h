/* Function prototypes. */

#ifndef PROTO_H
#define PROTO_H

/* Struct declarations. */
#if TEMP_CODE
struct dpeth;
#endif
struct proc;
struct time_info;
struct timer;

/* dummy.c */
_PROTOTYPE( void dummy_task, (void)					);

/* clock.c */
_PROTOTYPE( void clock_task, (void)					);
_PROTOTYPE( void clock_stop, (void)					);
_PROTOTYPE( clock_t get_uptime, (void)					);
_PROTOTYPE( unsigned long read_clock, (void)				);
_PROTOTYPE( void set_timer, (struct timer *tp, clock_t t, tmr_func_t f)	);
_PROTOTYPE( void reset_timer, (struct timer *tp)				);

/* klibc.c */
_PROTOTYPE( int katoi, (register const char *s));
_PROTOTYPE( void *kmemcpy, (void *s1, const void *s2, register size_t n));
_PROTOTYPE( void *kmemset, (void *s, register int c, register size_t n));
_PROTOTYPE( int kstrcmp, (register const char *s1, register const char *s2));
_PROTOTYPE( size_t kstrlen, (const char *s));
_PROTOTYPE( int kstrncmp,
	(register const char *s1, register const char *s2, register size_t n));
_PROTOTYPE( char *kstrncpy, 
	(char *s1, register const char *s2, register const size_t n));
_PROTOTYPE( unsigned long kstrtoul,
	(const char *string, char ** const end, int base)		);

/* kprintf.c */
#define NO_ARG 0
#define karg(arg) (karg_t) (arg)
_PROTOTYPE( void kprintf, (const char *fmt, karg_t arg)			);

/* main.c */
_PROTOTYPE( void main, (void)						);
_PROTOTYPE( void prepare_shutdown, (int how)					);
_PROTOTYPE( void stop_sequence, (struct timer *tp)				);
_PROTOTYPE( void shutdown, (struct timer *tp)				);

/* misc.c */
_PROTOTYPE( void panic, (_CONST char *s, int n)				);

#if TEMP_CODE
#if ENABLE_PCI
/* pci.c */
_PROTOTYPE( void pci_init, (void)					);
_PROTOTYPE( int pci_find_dev, (U8_t bus, U8_t dev, U8_t func,
							int *devindp)	);
_PROTOTYPE( int pci_first_dev, (int *devindp, u16_t *vidp, u16_t *didp)	);
_PROTOTYPE( int pci_next_dev, (int *devindp, u16_t *vidp, u16_t *didp)	);
_PROTOTYPE( void pci_reserve, (int devind)				);
_PROTOTYPE( void pci_ids, (int devind, u16_t *vidp, u16_t *didp)	);
_PROTOTYPE( char *pci_slot_name, (int devind)				);
_PROTOTYPE( char *pci_dev_name, (U16_t vid, U16_t did)			);
_PROTOTYPE( u8_t pci_attr_r8, (int devind, int port)			);
_PROTOTYPE( u16_t pci_attr_r16, (int devind, int port)			);
_PROTOTYPE( u32_t pci_attr_r32, (int devind, int port)			);
_PROTOTYPE( void pci_attr_w16, (int devind, int port, U16_t value)	);
_PROTOTYPE( void pci_attr_w32, (int devind, int port, u32_t value)	);

/* rtl8029.c */
_PROTOTYPE( int rtl_probe, (struct dpeth *dep)				);
#endif /* ENABLE_PCI */
/* rtl8139.c */
_PROTOTYPE( void rtl8139_task, (void)					);
#endif /* TEMP_CODE */


/* proc.c */
_PROTOTYPE( int sys_call, (int function, int src_dest, message *m_ptr)	);
_PROTOTYPE( void notify, (int proc_nr, int notify_type)			);
_PROTOTYPE( void unhold, (void)						);
_PROTOTYPE( void lock_pick_proc, (void)					);
_PROTOTYPE( void lock_ready, (struct proc *rp)				);
_PROTOTYPE( void lock_sched, (void)					);
_PROTOTYPE( void lock_unready, (struct proc *rp)			);

/* sb16_dsp.c, sb16_mixer.c */
_PROTOTYPE( void sb16dsp_task, (void)					);
_PROTOTYPE( void sb16mix_task, (void)					);

/* start.c */
_PROTOTYPE( void cstart, (U16_t cs, U16_t ds, U16_t mds,
				U16_t parmoff, U16_t parmsize)		);
_PROTOTYPE( char *getkenv, (_CONST char *key)				);

/* system.c */
_PROTOTYPE( void cause_sig, (int proc_nr, int sig_nr)			);
_PROTOTYPE( void clear_proc, (int proc_nr)				);
_PROTOTYPE( phys_bytes numap_local, (int proc_nr, vir_bytes vir_addr, 
		vir_bytes bytes)					);
_PROTOTYPE( void sys_task, (void)					);
_PROTOTYPE( int virtual_copy, (struct vir_addr *src, struct vir_addr *dst, 
				vir_bytes bytes) 			);
_PROTOTYPE( phys_bytes umap_local, (struct proc *rp, int seg, 
		vir_bytes vir_addr, vir_bytes bytes)			);
_PROTOTYPE( phys_bytes umap_remote, (struct proc *rp, int seg, 
		vir_bytes vir_addr, vir_bytes bytes)			);
_PROTOTYPE( phys_bytes umap_bios, (struct proc *rp, vir_bytes vir_addr,
		vir_bytes bytes)					);
_PROTOTYPE( int vir_copy, (int src_proc, vir_bytes src_vir,
		int dst_proc, vir_bytes dst_vir, vir_bytes bytes)	);
_PROTOTYPE( int generic_handler, (irq_hook_t *hook)			);
_PROTOTYPE( void timed_interrupt, (struct timer *tp)			);

/* table.c */
_PROTOTYPE( void mapdrivers, (void)					);

#if (CHIP == INTEL)

/* exception.c */
_PROTOTYPE( void exception, (unsigned vec_nr)				);

/* i8259.c */
_PROTOTYPE( void intr_init, (int mine)					);
_PROTOTYPE( void intr_handle, (irq_hook_t *hook)			);
_PROTOTYPE( void put_irq_handler, (irq_hook_t *hook, int irq,
						irq_handler_t handler)	);
/* klib*.s */
_PROTOTYPE( void int86, (void)						);
_PROTOTYPE( void cp_mess, (int src,phys_clicks src_clicks,vir_bytes src_offset,
		phys_clicks dst_clicks, vir_bytes dst_offset)		);
_PROTOTYPE( void enable_irq, (irq_hook_t *hook)				);
_PROTOTYPE( int disable_irq, (irq_hook_t *hook)				);
_PROTOTYPE( u16_t mem_rdw, (U16_t segm, vir_bytes offset)		);
_PROTOTYPE( void phys_copy, (phys_bytes source, phys_bytes dest,
		phys_bytes count)					);
_PROTOTYPE( void phys_insb, (Port_t port, phys_bytes buf, size_t count)	);
_PROTOTYPE( void phys_insw, (Port_t port, phys_bytes buf, size_t count)	);
_PROTOTYPE( void phys_outsb, (Port_t port, phys_bytes buf, size_t count));
_PROTOTYPE( void phys_outsw, (Port_t port, phys_bytes buf, size_t count));
_PROTOTYPE( void reset, (void)						);
_PROTOTYPE( void level0, (void (*func)(void))				);
_PROTOTYPE( void monitor, (void)					);
_PROTOTYPE( void read_tsc, (unsigned long *low, unsigned long *high)	);

/* mpx*.s */
_PROTOTYPE( void idle_task, (void)					);
_PROTOTYPE( void restart, (void)					);

/* The following are never called from C (pure asm procs). */

/* Exception handlers (real or protected mode), in numerical order. */
void _PROTOTYPE( int00, (void) ), _PROTOTYPE( divide_error, (void) );
void _PROTOTYPE( int01, (void) ), _PROTOTYPE( single_step_exception, (void) );
void _PROTOTYPE( int02, (void) ), _PROTOTYPE( nmi, (void) );
void _PROTOTYPE( int03, (void) ), _PROTOTYPE( breakpoint_exception, (void) );
void _PROTOTYPE( int04, (void) ), _PROTOTYPE( overflow, (void) );
void _PROTOTYPE( int05, (void) ), _PROTOTYPE( bounds_check, (void) );
void _PROTOTYPE( int06, (void) ), _PROTOTYPE( inval_opcode, (void) );
void _PROTOTYPE( int07, (void) ), _PROTOTYPE( copr_not_available, (void) );
void				  _PROTOTYPE( double_fault, (void) );
void				  _PROTOTYPE( copr_seg_overrun, (void) );
void				  _PROTOTYPE( inval_tss, (void) );
void				  _PROTOTYPE( segment_not_present, (void) );
void				  _PROTOTYPE( stack_exception, (void) );
void				  _PROTOTYPE( general_protection, (void) );
void				  _PROTOTYPE( page_fault, (void) );
void				  _PROTOTYPE( copr_error, (void) );

/* Hardware interrupt handlers. */
_PROTOTYPE( void hwint00, (void) );
_PROTOTYPE( void hwint01, (void) );
_PROTOTYPE( void hwint02, (void) );
_PROTOTYPE( void hwint03, (void) );
_PROTOTYPE( void hwint04, (void) );
_PROTOTYPE( void hwint05, (void) );
_PROTOTYPE( void hwint06, (void) );
_PROTOTYPE( void hwint07, (void) );
_PROTOTYPE( void hwint08, (void) );
_PROTOTYPE( void hwint09, (void) );
_PROTOTYPE( void hwint10, (void) );
_PROTOTYPE( void hwint11, (void) );
_PROTOTYPE( void hwint12, (void) );
_PROTOTYPE( void hwint13, (void) );
_PROTOTYPE( void hwint14, (void) );
_PROTOTYPE( void hwint15, (void) );

/* Software interrupt handlers, in numerical order. */
_PROTOTYPE( void trp, (void) );
_PROTOTYPE( void s_call, (void) ), _PROTOTYPE( p_s_call, (void) );
_PROTOTYPE( void level0_call, (void) );

/* protect.c */
_PROTOTYPE( void prot_init, (void)					);
_PROTOTYPE( void init_codeseg, (struct segdesc_s *segdp, phys_bytes base,
		vir_bytes size, int privilege)				);
_PROTOTYPE( void init_dataseg, (struct segdesc_s *segdp, phys_bytes base,
		vir_bytes size, int privilege)				);
_PROTOTYPE( phys_bytes seg2phys, (U16_t seg)				);
_PROTOTYPE( void phys2seg, (u16_t *seg, vir_bytes *off, phys_bytes phys));
_PROTOTYPE( void enable_iop, (struct proc *pp)				);
_PROTOTYPE( void alloc_segments, (struct proc *rp)			);


#endif /* (CHIP == INTEL) */

#if (CHIP == M68000)
/* M68000 specific prototypes go here. */
#endif /* (CHIP == M68000) */

#endif /* PROTO_H */
