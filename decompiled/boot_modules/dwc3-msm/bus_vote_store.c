__int64 __fastcall bus_vote_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x20
  __int64 v5; // x19
  int v8; // w1

  v4 = *(_QWORD *)(a1 + 152);
  if ( (*(_BYTE *)(v4 + 2804) & 1) != 0 )
    return -22;
  v5 = a4;
  if ( (sysfs_streq(a3, "min") & 1) != 0 )
  {
    v8 = 3;
    goto LABEL_7;
  }
  if ( (sysfs_streq(a3, "max") & 1) != 0 )
  {
    v8 = 4;
LABEL_7:
    *(_DWORD *)(v4 + 708) = v8;
    if ( *(_DWORD *)(v4 + 832) )
      return v5;
LABEL_8:
    dwc3_msm_update_bus_bw(v4, v8);
    return v5;
  }
  if ( (sysfs_streq(a3, "cancel") & 1) == 0 )
  {
    dev_err(a1, "min/max/cancel only.\n");
    return -22;
  }
  *(_DWORD *)(v4 + 708) = 0;
  if ( !*(_DWORD *)(v4 + 832) )
  {
    if ( *(_BYTE *)(v4 + 736) == 1 && *(_DWORD *)(v4 + 740) == 3 )
      v8 = 2;
    else
      v8 = *(_DWORD *)(v4 + 704);
    goto LABEL_8;
  }
  return v5;
}
