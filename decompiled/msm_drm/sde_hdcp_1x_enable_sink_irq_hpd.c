__int64 __fastcall sde_hdcp_1x_enable_sink_irq_hpd(__int64 result)
{
  unsigned __int8 *v1; // x9
  unsigned int v2; // w8
  __int64 v4; // x19
  int v5; // w23
  unsigned int v6; // w20
  char *v7; // x21
  int v8; // w25
  char v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(unsigned __int8 **)(result + 984);
  v9 = 1;
  v2 = *v1;
  if ( v2 >= 0x10 && (v2 & 0xE) != 0 )
  {
    v4 = result;
    if ( *(_DWORD *)(result + 44) == 2 && *(_DWORD *)(result + 1000) == 1 )
    {
      v5 = *(_DWORD *)(result + 1428);
      v6 = *(_DWORD *)(result + 1424);
      v7 = &v9;
      while ( 1 )
      {
        v8 = v5 >= 16 ? 16 : v5;
        result = drm_dp_dpcd_write(*(_QWORD *)(v4 + 936), v6, v7, v8);
        if ( v8 != (_DWORD)result )
          break;
        v5 -= v8;
        v7 += v8;
        v6 += v8;
        if ( v5 <= 0 )
          goto LABEL_13;
      }
      result = printk(&unk_26ECF1, "sde_hdcp_1x_write");
    }
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
