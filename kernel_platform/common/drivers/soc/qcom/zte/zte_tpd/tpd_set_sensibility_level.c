__int64 __fastcall tpd_set_sensibility_level(__int64 a1, unsigned __int8 a2, __int64 a3)
{
  _QWORD *v3; // x19
  __int64 v5; // x9
  __int64 v6; // x2
  int v7; // w8
  int v8; // w1
  void *v10; // x0

  v3 = *(_QWORD **)(a1 + 3072);
  printk(unk_34878, "tpd_set_sensibility_level", a3);
  if ( v3 )
  {
    v5 = v3[78];
    if ( *(_DWORD *)(v5 + 184) && (*(_BYTE *)(v5 + 188) & 1) != 0 )
      v6 = 0;
    else
      v6 = *(unsigned int *)(*v3 + 524LL);
    v7 = *((_DWORD *)v3 + 351);
    if ( (a2 & 0xFC) != 0 )
      v8 = 4;
    else
      v8 = a2;
    *((_DWORD *)v3 + 383) = v8;
    if ( v7 == 1 )
    {
      if ( (syna_dev_set_sensibility_level(v3, v8, v6) & 0x80000000) == 0 )
        return 0;
      v10 = unk_36905;
    }
    else
    {
      v10 = unk_3B5E0;
    }
    printk(v10, "tpd_set_sensibility_level", v6);
    return 0;
  }
  return 4294967274LL;
}
