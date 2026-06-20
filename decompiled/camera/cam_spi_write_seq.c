__int64 __fastcall cam_spi_write_seq(__int64 a1, unsigned int a2, char *a3, unsigned int a4, unsigned int a5)
{
  __int64 v6; // x8
  unsigned int v7; // w19
  unsigned int v10; // w22
  unsigned int v12; // w28
  unsigned __int8 v13; // w8
  unsigned __int8 *v14; // x24
  int v15; // w8
  unsigned int v16; // w9
  unsigned int v17; // w27
  unsigned int v18; // w0

  if ( a4 - 5 < 0xFFFFFFFC )
    return 4294967274LL;
  v6 = *(_QWORD *)(a1 + 24);
  v7 = a5;
  v10 = a2;
  v12 = *(unsigned __int16 *)(v6 + 50);
  v13 = *(_BYTE *)(v6 + 24) + *(_BYTE *)(v6 + 25) + 1;
  if ( a2 % v12 + a5 <= v12 )
  {
    v14 = (unsigned __int8 *)_kmalloc_noprof((unsigned __int16)(a5 + v13), 3265);
    if ( v14 )
    {
      v18 = cam_spi_page_program(a1, v10, a3, a4, v7, v14);
      if ( (v18 & 0x80000000) != 0 )
      {
LABEL_15:
        v7 = v18;
        printk(&unk_41F554);
        goto LABEL_16;
      }
      v7 = 0;
LABEL_16:
      kfree(v14);
      return v7;
    }
  }
  else
  {
    v14 = (unsigned __int8 *)_kmalloc_noprof((unsigned __int16)(v12 + v13), 3265);
    if ( v14 )
    {
      if ( v7 )
      {
        while ( 1 )
        {
          v15 = v10 % v12;
          v16 = v10 % v12 + v7;
          if ( v16 >= v12 )
            v16 = v12;
          v17 = v16 - v15;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, unsigned int))cam_print_log)(
            3,
            0x4000000000LL,
            1,
            "cam_spi_write_seq",
            539,
            "Addr: 0x%x curr_len: 0x%x pgSize: %d",
            v10,
            v16 - v15,
            v12);
          v18 = cam_spi_page_program(a1, v10, a3, a4, v17, v14);
          if ( (v18 & 0x80000000) != 0 )
            goto LABEL_15;
          a3 += v17;
          v7 -= v17;
          v10 += v17;
          if ( !v7 )
            goto LABEL_16;
        }
      }
      v7 = -22;
      goto LABEL_16;
    }
  }
  printk(&unk_417E16);
  return 4294967284LL;
}
