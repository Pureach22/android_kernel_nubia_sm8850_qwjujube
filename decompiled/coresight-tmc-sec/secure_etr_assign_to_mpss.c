__int64 __fastcall secure_etr_assign_to_mpss(__int64 a1)
{
  __int64 v2; // x9
  __int64 v3; // x8
  __int64 v4; // x9
  __int64 v5; // x20
  _QWORD *v6; // x0
  __int64 v7; // x9

  v2 = **(_QWORD **)(a1 + 8);
  v3 = *(unsigned int *)(v2 + 4);
  if ( (int)v3 < 1 )
  {
LABEL_7:
    v5 = 0;
  }
  else
  {
    v4 = *(_QWORD *)(v2 + 8);
    while ( 1 )
    {
      v5 = *(_QWORD *)(*(_QWORD *)v4 + 16LL);
      if ( v5 )
      {
        if ( *(_DWORD *)(v5 + 8) == 4 )
          break;
      }
      --v3;
      v4 += 8;
      if ( !v3 )
        goto LABEL_7;
    }
  }
  v6 = (_QWORD *)_kmalloc_cache_noprof(dma_set_coherent_mask, 3520, 24);
  if ( !v6 )
    return 4294967284LL;
  v7 = *(_QWORD *)(a1 + 248);
  *v6 = 0x200000001LL;
  v6[1] = *(_QWORD *)(v7 + 8);
  v6[2] = *(_QWORD *)(v7 + 16);
  if ( v5 )
    return coresight_qmi_etr_assign(v5);
  else
    return 0;
}
