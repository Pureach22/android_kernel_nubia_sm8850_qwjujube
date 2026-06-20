__int64 __fastcall hfi_crtc_add_base_prop_helper(int a1, __int64 a2, __int64 a3, int *a4, unsigned int a5)
{
  __int64 result; // x0
  __int64 v7; // x21
  __int64 v11; // x8
  int v12; // w4
  _QWORD v13[2]; // [xsp+0h] [xbp-10h] BYREF

  result = 4294967274LL;
  v13[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 && a3 )
  {
    v7 = *(_QWORD *)(a2 + 8032);
    if ( (unsigned int)(a1 - 131089) > 6 )
    {
      printk(&unk_21D123, "_hfi_crtc_add_base_prop_helper");
      result = 4294967274LL;
    }
    else
    {
      if ( (sde_crtc_property_is_dirty(a3, a5) & 1) != 0 )
      {
        v11 = a5 > 0x1E ? 0LL : *(_QWORD *)(a3 + 32LL * a5 + 800);
        v13[0] = v11;
        hfi_util_u32_prop_helper_add_prop(a4, a1, 2, v13, 8u);
        if ( (_drm_debug & 4) != 0 )
        {
          if ( v7 )
            v12 = *(_DWORD *)(*(_QWORD *)v7 + 112LL);
          else
            v12 = -1;
          _drm_dev_dbg(0, 0, 0, "crtc%d done adding HFI prop:0x%x\n", v12, a1);
        }
      }
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
