__int64 __fastcall sde_validate_ltm_roiv1_3(_DWORD *a1, _DWORD *a2)
{
  _DWORD *v2; // x3
  int v3; // w2
  _DWORD *v5; // x19

  if ( a1 && a2 )
  {
    v2 = *(_DWORD **)a2;
    if ( !*(_QWORD *)a2 )
      return 0;
    v3 = a2[2];
    if ( v3 == 24 )
    {
      if ( (HIWORD(v2[4]) & 0x1FF) + (v2[4] & 0x1FFu) >= 0x101 )
      {
        v5 = *(_DWORD **)a2;
        printk(&unk_224D71, a2);
        v2 = v5;
      }
      if ( (HIWORD(v2[5]) & 0x1FF) + (v2[5] & 0x1FFu) >= 0x101 )
        printk(&unk_232373, a2);
      return 0;
    }
    _drm_err("invalid ltm_cfg payload\tdspp: %d\tlen: %u\tpayload: %pK\n", a1[16], v3, v2);
  }
  else
  {
    _drm_err("invalid parameter\tctx: %pK\tcfg: %pK\n", a1, a2);
  }
  return 4294967274LL;
}
