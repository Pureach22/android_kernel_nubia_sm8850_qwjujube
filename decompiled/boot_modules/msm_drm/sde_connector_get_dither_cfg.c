__int64 __fastcall sde_connector_get_dither_cfg(__int64 a1, __int64 a2, __int64 *a3, _QWORD *a4, unsigned __int8 a5)
{
  unsigned int v10; // w20
  __int64 blob; // x0
  _QWORD v13[2]; // [xsp+0h] [xbp-10h] BYREF

  v13[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13[0] = 0;
  if ( a1 && a2 && a3 )
  {
    v10 = -61;
    if ( (msm_property_is_dirty(a1 + 3312, a2 + 448, 4) & 1) != 0 || (a5 & 1) != 0 )
    {
      blob = msm_property_get_blob(a1 + 3312, a2 + 448, v13);
      *a3 = blob;
      if ( ((blob == 0) & a5) != 0 )
        v10 = -61;
      else
        v10 = 0;
      if ( blob )
      {
        v10 = 0;
        *a4 = v13[0];
      }
    }
  }
  else
  {
    printk(&unk_26FEB0, "sde_connector_get_dither_cfg");
    v10 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return v10;
}
