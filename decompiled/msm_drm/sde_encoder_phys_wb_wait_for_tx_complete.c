__int64 __fastcall sde_encoder_phys_wb_wait_for_tx_complete(__int64 *a1)
{
  __int64 result; // x0
  __int64 v3; // x8
  __int64 v4; // x21
  unsigned int v5; // w20
  __int64 v6; // x1
  __int64 v7; // x8

  if ( *((_DWORD *)a1 + 219) )
  {
    result = sde_encoder_phys_wb_wait_for_idle(a1, 1);
    if ( *((_DWORD *)a1 + 208) )
      return result;
  }
  else
  {
    result = 0;
    if ( *((_DWORD *)a1 + 208) )
      return result;
  }
  if ( *((_BYTE *)a1 + 2290) == 1 )
  {
    v3 = a1[352];
    v4 = *a1;
    v5 = result;
    *((_DWORD *)a1 + 208) = 1;
    if ( v3 )
    {
      v6 = a1[353];
      if ( v6 )
      {
        msm_framebuffer_cleanup(v3, v6);
        drm_mode_object_put(a1[352] + 24);
        a1[352] = 0;
        a1[353] = 0;
      }
    }
    v7 = *(_QWORD *)(v4 + 1360);
    if ( v7 )
      *(_DWORD *)(v7 + 7872) &= ~(1 << *(_DWORD *)(*a1 + 68));
    a1[367] = 0;
    a1[54] = 0;
    a1[52] = 0;
    *((_BYTE *)a1 + 2290) = 0;
    *((_DWORD *)a1 + 219) = 0;
    *((_DWORD *)a1 + 220) = 0;
    *((_DWORD *)a1 + 221) = 0;
    sde_encoder_phys_wb_irq_ctrl(a1, 0);
    return v5;
  }
  return result;
}
