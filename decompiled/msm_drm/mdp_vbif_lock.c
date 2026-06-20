__int64 __fastcall mdp_vbif_lock(__int64 result, char a2)
{
  __int64 v2; // x8
  __int64 v3; // x8
  __int64 v4; // x9
  __int64 v5; // x8
  __int64 v6; // x0

  v2 = *(_QWORD *)(result + 168);
  if ( !v2 )
    return printk(&unk_21A0D9, "mdp_vbif_lock");
  v3 = *(_QWORD *)(v2 + 56);
  if ( !v3 )
    return printk(&unk_21A0D9, "mdp_vbif_lock");
  v4 = *(_QWORD *)(v3 + 8);
  if ( !v4 )
    return printk(&unk_21A0D9, "mdp_vbif_lock");
  v5 = *(_QWORD *)(v4 + 3512);
  if ( v5 && !*(_DWORD *)(v5 + 32) || (v5 = *(_QWORD *)(v4 + 3520)) != 0 && !*(_DWORD *)(v5 + 32) )
  {
    v6 = v5 + 288;
    if ( (a2 & 1) != 0 )
      return mutex_lock(v6);
    else
      return mutex_unlock(v6);
  }
  else if ( (_drm_debug & 4) != 0 )
  {
    return _drm_dev_dbg(0, 0, 0, "invalid vbif structure\n");
  }
  return result;
}
