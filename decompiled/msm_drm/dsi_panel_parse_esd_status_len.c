__int64 __fastcall dsi_panel_parse_esd_status_len(__int64 *a1, __int64 a2, unsigned __int64 *a3, int a4)
{
  __int64 (__fastcall *v8)(__int64, __int64, int *); // x8
  __int64 v9; // x0
  __int64 result; // x0
  unsigned __int64 v11; // x0
  unsigned __int64 v12; // x2
  unsigned int (__fastcall *v13)(__int64, __int64, unsigned __int64, __int64); // x8
  __int64 v14; // x0
  __int64 v15; // x3
  int v16; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = (__int64 (__fastcall *)(__int64, __int64, int *))a1[12];
  v9 = *a1;
  v16 = 0;
  if ( *((_DWORD *)v8 - 1) != -1265043226 )
    __break(0x8228u);
  result = v8(v9, a2, &v16);
  if ( result )
  {
    v16 >>= 2;
    if ( v16 == a4 )
    {
      if ( v16 < 0 )
      {
        *a3 = 0;
      }
      else
      {
        v11 = _kmalloc_noprof(4LL * (unsigned int)v16, 3520);
        v12 = v11;
        *a3 = v11;
        if ( v11 && v11 < 0xFFFFFFFFFFFFF001LL )
        {
          v13 = (unsigned int (__fastcall *)(__int64, __int64, unsigned __int64, __int64))a1[7];
          v14 = *a1;
          v15 = v16;
          if ( *((_DWORD *)v13 - 1) != 905330014 )
            __break(0x8228u);
          if ( v13(v14, a2, v12, v15) )
          {
            drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: cannot get values from dts\n");
            kfree(*a3);
            result = 0;
            *a3 = 0;
          }
          else
          {
            result = 1;
          }
          goto LABEL_17;
        }
      }
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Error allocating memory for property\n");
    }
    else
    {
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: request property(%d) do not match cmd count(%d)\n",
        v16,
        a4);
    }
    result = 0;
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
