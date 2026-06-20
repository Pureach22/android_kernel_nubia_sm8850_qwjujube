size_t __fastcall sde_demura_pu_cfg(__int64 a1, __int64 *a2)
{
  __int64 v2; // x22
  unsigned int v3; // w9
  unsigned int v4; // w8
  unsigned int v5; // w20
  int v8; // w7
  __int16 v9; // w8

  if ( !a1 )
    return _drm_err("invalid parameter ctx %pK", nullptr);
  if ( a2 )
  {
    v2 = *a2;
    if ( *a2 )
    {
      v3 = *((_DWORD *)a2 + 23);
      if ( *((_DWORD *)a2 + 24) >= v3 )
        v4 = 0x1000000;
      else
        v4 = 0x2000000;
      v5 = v4 / v3 * *(unsigned __int16 *)(v2 + 6);
      goto LABEL_11;
    }
  }
  else
  {
    v2 = 0;
  }
  v5 = 0;
LABEL_11:
  sde_reg_write(
    a1,
    (unsigned int)(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 568LL) + 96),
    v5,
    "dspp->cap->sblk->demura.base + 0x60");
  if ( v2 )
  {
    v8 = *(unsigned __int16 *)(v2 + 6);
    v9 = *(_WORD *)(v2 + 10);
  }
  else
  {
    v8 = -1;
    LOBYTE(v9) = -1;
  }
  return sde_evtlog_log(sde_dbg_base_evtlog, "sde_demura_pu_cfg", 777, -1, 96, v5, *(_DWORD *)(a1 + 64), v8, v9);
}
