__int64 __fastcall kgsl_allocate_secure(__int64 a1, _QWORD *a2, __int64 a3, unsigned __int64 a4, int a5)
{
  unsigned __int64 v5; // x20
  __int64 result; // x0
  unsigned int v9; // w22
  __int64 v10; // x0
  __int64 v11; // x21
  __int64 v12; // x23
  unsigned int v13; // w0
  unsigned int v14; // w20
  unsigned int v15; // w0
  unsigned int v16; // w22
  unsigned int v23; // w9
  unsigned __int64 v26; // x8
  unsigned __int64 v27; // x8
  __int64 v28; // [xsp+0h] [xbp-20h] BYREF
  int v29; // [xsp+Ch] [xbp-14h] BYREF
  int v30; // [xsp+10h] [xbp-10h] BYREF
  int v31; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v32; // [xsp+18h] [xbp-8h]

  v5 = (a3 + 4095) & 0xFFFFFFFFFFFFF000LL;
  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( v5 - 0x100000000LL < 0xFFFFFFFF00000001LL )
  {
    result = 4294967274LL;
    goto LABEL_25;
  }
  kgsl_memdesc_init(a1, (__int64)a2, a4);
  _X8 = (unsigned int *)(a2 + 6);
  __asm { PRFM            #0x11, [X8] }
  do
    v23 = __ldxr(_X8);
  while ( __stxr(v23 | a5, _X8) );
  v28 = 0;
  a2[5] = v5;
  if ( (a5 & 0x200) != 0 )
  {
    a2[8] = &kgsl_secure_system_ops;
    result = kgsl_system_alloc_pages(a2, &v28);
    if ( (result & 0x80000000) != 0 )
      goto LABEL_25;
  }
  else
  {
    a2[8] = &kgsl_secure_page_ops;
    result = kgsl_alloc_pages(a2, &v28);
    if ( (result & 0x80000000) != 0 )
      goto LABEL_25;
  }
  v9 = result;
  v10 = _kmalloc_cache_noprof(raw_read_lock, 3520, 16);
  v11 = v10;
  v12 = v28;
  if ( !v10 )
  {
    a2[12] = v28;
    kgsl_free_pages(a2);
    result = 4294967284LL;
    goto LABEL_25;
  }
  v13 = sg_alloc_table_from_pages_segment(v10, v28, v9, 0, v5, 0xFFFFFFFFLL, 3264);
  if ( v13 )
  {
    v14 = v13;
    kfree(v11);
    a2[12] = v12;
    kgsl_free_pages(a2);
    result = v14;
    goto LABEL_25;
  }
  kvfree(v12);
  a2[7] = v11;
  v31 = 6;
  v29 = 10;
  v30 = 3;
  do
    v15 = hyp_assign_table(v11, &v30, 1, &v29, &v31, 1);
  while ( v15 == -11 );
  if ( v15 == -99 )
  {
    v16 = -99;
    printk(&unk_13A8CD);
    goto LABEL_16;
  }
  if ( v15 )
  {
    v16 = v15;
    kgsl_free_pages_from_sgt(a2);
LABEL_16:
    sg_free_table(v11);
    kfree(v11);
    a2[7] = 0;
    result = v16;
    goto LABEL_25;
  }
  _X9 = &qword_3A8D8;
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v26 = __ldxr((unsigned __int64 *)&qword_3A8D8);
    v27 = v26 + v5;
  }
  while ( __stlxr(v27, (unsigned __int64 *)&qword_3A8D8) );
  __dmb(0xBu);
  result = 0;
  if ( v27 > qword_3A8E0 )
    qword_3A8E0 = v27;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
