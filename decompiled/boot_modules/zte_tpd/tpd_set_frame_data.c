__int64 __fastcall tpd_set_frame_data(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 v3; // x19
  __int64 v5; // x2
  __int64 v6; // x9
  unsigned int v7; // w21
  void *v9; // x0

  v3 = *(_QWORD *)(a1 + 3072);
  printk(&unk_34878, "tpd_set_frame_data", a3);
  if ( v3 )
  {
    v6 = *(_QWORD *)(v3 + 624);
    if ( *(_DWORD *)(v6 + 184) && (*(_BYTE *)(v6 + 188) & 1) != 0 )
      v7 = 0;
    else
      v7 = *(_DWORD *)(*(_QWORD *)v3 + 524LL);
    if ( *(_DWORD *)(v3 + 1404) == 1 )
    {
      *(_DWORD *)(v3 + 1504) = a2;
      zte_reset_frame_list(v3);
      if ( (syna_dev_get_frame_data((_QWORD *)v3, a2, v7) & 0x80000000) == 0 )
        return 0;
      v9 = &unk_345B2;
    }
    else
    {
      v9 = &unk_3B5E0;
    }
    printk(v9, "tpd_set_frame_data", v5);
    return 0;
  }
  return 4294967274LL;
}
