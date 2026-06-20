__int64 __fastcall sde_plane_set_ot_limit(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x19
  __int64 v4; // x9
  __int64 v6; // x10
  int v7; // w9
  bool v8; // w8
  int v9; // w11
  char v10; // w12
  int v11; // w0
  __int64 v12; // x8
  __int64 result; // x0
  _DWORD v14[5]; // [xsp+8h] [xbp-28h] BYREF
  int v15; // [xsp+1Ch] [xbp-14h]
  int v16; // [xsp+20h] [xbp-10h]
  int v17; // [xsp+24h] [xbp-Ch]
  __int64 v18; // [xsp+28h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_QWORD *)a1 )
  {
    v2 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
    if ( v2 && (v3 = *(_QWORD *)(v2 + 8)) != 0 )
    {
      v4 = *(_QWORD *)(a1 + 2208);
      if ( v4 )
      {
        v6 = *(_QWORD *)(v4 + 56);
        v7 = *(_DWORD *)(v4 + 48);
        v8 = 0;
        v9 = *(unsigned __int16 *)(a1 + 2292);
        v10 = *(_BYTE *)(a1 + 2381);
        v15 = 0;
        v14[0] = *(_DWORD *)(v6 + 56);
        v14[1] = v7;
        LODWORD(v6) = *(unsigned __int16 *)(a1 + 2294);
        v14[2] = v9;
        v14[3] = v6;
        if ( (v10 & 1) == 0 )
          v8 = *(_DWORD *)(a1 + 2384) != 2;
        BYTE1(v15) = v8;
        v11 = drm_mode_vrefresh(a2 + 176);
        v12 = *(_QWORD *)(a1 + 2208);
        v14[4] = v11;
        LOBYTE(v15) = 1;
        LODWORD(v12) = *(_DWORD *)(*(_QWORD *)(v12 + 56) + 60LL);
        v16 = 0;
        v17 = v12;
        result = sde_vbif_set_ot_limit(v3, v14);
      }
      else
      {
        result = printk(&unk_262833, "_sde_plane_set_ot_limit");
      }
    }
    else
    {
      result = printk(&unk_25EA03, "_sde_plane_set_ot_limit");
    }
  }
  else
  {
    result = printk(&unk_224747, "_sde_plane_set_ot_limit");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
