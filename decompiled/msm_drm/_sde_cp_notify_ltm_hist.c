__int64 __fastcall sde_cp_notify_ltm_hist(_BYTE *a1, _DWORD *a2)
{
  __int64 v4; // x20
  int v5; // w8
  __int64 result; // x0
  __int64 v7; // [xsp+0h] [xbp-20h] BYREF
  int v8; // [xsp+8h] [xbp-18h]
  _QWORD v9[2]; // [xsp+10h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9[0] = 0;
  v8 = 0;
  v7 = 0;
  if ( a1 && a2 )
  {
    mutex_lock(a1 + 7704);
    v4 = raw_spin_lock_irqsave(a1 + 7752);
    if ( *((_DWORD *)a1 + 1898) )
    {
      if ( (a1[7672] & 1) == 0 )
      {
        raw_spin_unlock_irqrestore(a1 + 7752, v4);
        mutex_unlock(a1 + 7704);
        result = _drm_dev_dbg(0, 0, 1, "ltm histogram is disabled\n");
        goto LABEL_9;
      }
      v5 = a2[7];
      LODWORD(v7) = a2[6];
      HIDWORD(v7) = v5;
      v9[0] = 0xC80000008LL;
      _drm_dev_dbg(0, 0, 1, "notify with LTM hist event drm_fb_id %d\n", v7);
      msm_mode_object_event_notify(a1 + 112, *(_QWORD *)a1, v9, &v7);
    }
    raw_spin_unlock_irqrestore(a1 + 7752, v4);
    result = mutex_unlock(a1 + 7704);
  }
  else
  {
    result = _drm_err("invalid drm_crtc %pK or arg %pK\n", a1, a2);
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
