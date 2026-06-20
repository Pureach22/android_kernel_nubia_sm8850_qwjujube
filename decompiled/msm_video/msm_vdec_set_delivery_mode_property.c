__int64 __fastcall msm_vdec_set_delivery_mode_property(__int64 a1, unsigned int a2)
{
  __int64 v3; // x8
  __int64 v4; // x5
  __int64 result; // x0
  __int64 v6; // x20
  int v7; // [xsp+8h] [xbp-88h] BYREF
  __int64 v8; // [xsp+Ch] [xbp-84h]
  __int64 v9; // [xsp+14h] [xbp-7Ch]
  __int64 v10; // [xsp+1Ch] [xbp-74h]
  __int64 v11; // [xsp+24h] [xbp-6Ch]
  __int64 v12; // [xsp+2Ch] [xbp-64h]
  __int64 v13; // [xsp+34h] [xbp-5Ch]
  __int64 v14; // [xsp+3Ch] [xbp-54h]
  __int64 v15; // [xsp+44h] [xbp-4Ch]
  __int64 v16; // [xsp+4Ch] [xbp-44h]
  __int64 v17; // [xsp+54h] [xbp-3Ch]
  __int64 v18; // [xsp+5Ch] [xbp-34h]
  __int64 v19; // [xsp+64h] [xbp-2Ch]
  __int64 v20; // [xsp+6Ch] [xbp-24h]
  __int64 v21; // [xsp+74h] [xbp-1Ch]
  __int64 v22; // [xsp+7Ch] [xbp-14h]
  int v23; // [xsp+84h] [xbp-Ch]
  __int64 v24; // [xsp+88h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = 0;
  v22 = 0;
  v21 = 0;
  v20 = 0;
  v19 = 0;
  v18 = 0;
  v17 = 0;
  v16 = 0;
  v15 = 0;
  v14 = 0;
  v13 = 0;
  v12 = 0;
  v11 = 0;
  v10 = 0;
  v9 = 0;
  v8 = 0;
  if ( a1 && (msm_vidc_debug & 2) != 0 )
  {
    v6 = a1;
    printk(&unk_8B2D6, "high", a1 + 340, "msm_vdec_set_delivery_mode_property", a2);
    a1 = v6;
  }
  v7 = 2;
  if ( !a2 )
  {
    if ( *(_QWORD *)(a1 + 13928) )
    {
      v3 = 13940;
      goto LABEL_10;
    }
LABEL_11:
    v4 = 4;
    goto LABEL_12;
  }
  if ( (*(_BYTE *)(a1 + 5544) & 0x80) == 0 || (~*(_DWORD *)(a1 + 5528) & 9LL) != 0 )
    goto LABEL_11;
  v3 = 5540;
LABEL_10:
  v4 = 8;
  LODWORD(v8) = *(_DWORD *)(a1 + v3);
LABEL_12:
  result = msm_vidc_session_command(a1, 16777226, a2, 11, &v7, v4, "msm_vdec_set_delivery_mode_property");
  _ReadStatusReg(SP_EL0);
  return result;
}
