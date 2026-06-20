__int64 __fastcall qcom_sg_mmap(__int64 a1, unsigned __int64 *a2)
{
  __int64 v2; // x22
  unsigned __int64 v3; // x20
  unsigned __int64 v5; // x21
  unsigned __int64 v6; // x21
  __int64 v7; // x0
  unsigned int v8; // w23
  unsigned __int64 v9; // x8
  unsigned __int64 v10; // x8
  __int64 v11; // x26
  unsigned __int64 v12; // x11
  signed __int64 v13; // x9
  __int64 v14; // x21
  unsigned int v15; // w0
  unsigned int v16; // w19

  v2 = *(_QWORD *)(a1 + 112);
  v3 = *a2;
  v5 = a2[10];
  mem_buf_vmperm_pin(*(_QWORD *)(v2 + 120));
  if ( (mem_buf_vmperm_can_mmap(*(_QWORD *)(v2 + 120), a2) & 1) == 0 )
  {
    v16 = -1;
    goto LABEL_16;
  }
  a2[9] = (unsigned __int64)qcom_sg_vm_ops;
  a2[12] = *(_QWORD *)(v2 + 120);
  if ( *(_BYTE *)(v2 + 112) == 1 )
    a2[3] = a2[3] & 0xFF9FFFFFFFFFFFE3LL | 0x60000000000008LL;
  if ( !*(_DWORD *)(v2 + 88) )
    return 0;
  v6 = v5 << 12;
  v7 = *(_QWORD *)(v2 + 80);
  v8 = 0;
  while ( 1 )
  {
    v9 = *(unsigned int *)(v7 + 12);
    if ( v6 >= v9 )
    {
      v6 -= v9;
      goto LABEL_7;
    }
    v10 = v9 - v6;
    v11 = v7;
    v12 = a2[1];
    v13 = (*(_QWORD *)v7 & 0xFFFFFFFFFFFFFFFCLL)
        + (v6 >> 12 << 6)
        - -64 * ((__int64)memstart_addr >> 12)
        + 0x140000000LL;
    v14 = v10 >= v12 - v3 ? v12 - v3 : v10;
    v15 = remap_pfn_range(a2, v3, v13 >> 6, v14, a2[3]);
    if ( v15 )
      break;
    v3 += v14;
    if ( v3 >= a2[1] )
      return 0;
    v6 = 0;
    v7 = v11;
LABEL_7:
    ++v8;
    v7 = sg_next(v7);
    if ( v8 >= *(_DWORD *)(v2 + 88) )
      return 0;
  }
  v16 = v15;
LABEL_16:
  mem_buf_vmperm_unpin(*(_QWORD *)(v2 + 120));
  return v16;
}
