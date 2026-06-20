__int64 __fastcall msm_vidc_set_auto_framerate(__int64 a1)
{
  __int64 result; // x0
  _QWORD *v3; // x15
  _QWORD *v4; // x16
  unsigned int v5; // w9
  int v6; // w12
  int v7; // w0
  int v8; // w13
  _QWORD *v9; // x14
  unsigned __int64 v10; // x12
  unsigned __int64 v11; // x12
  unsigned int v12; // w9
  __int64 v13; // x8
  __int64 v14; // x4
  __int64 v15; // x2
  unsigned int v16; // w19
  int v17; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v18; // [xsp+8h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_QWORD *)(*(_QWORD *)(a1 + 320) + 4576LL)
    || *(_DWORD *)(a1 + 312) == 8
    || *(_QWORD *)(a1 + 23336)
    || !*(_QWORD *)(a1 + 10568) )
  {
    goto LABEL_4;
  }
  result = msm_vidc_update_timestamp_rate();
  if ( (_DWORD)result )
    goto LABEL_5;
  v3 = *(_QWORD **)(a1 + 3208);
  if ( v3 == (_QWORD *)(a1 + 3208) )
    goto LABEL_4;
  v4 = nullptr;
  v5 = 0;
  v6 = 0;
  v7 = 0;
  do
  {
    v9 = v3;
    if ( v4 )
    {
      v10 = v3[2] - v4[2];
      if ( v10 )
        v11 = (((v10 >> 1) + 1000000) / v10) << 16;
      else
        LODWORD(v11) = *(_DWORD *)(a1 + 38696);
      if ( *(_QWORD *)(a1 + 19456) < (__int64)(unsigned int)v11 )
        v11 = *(_QWORD *)(a1 + 19456);
      if ( *(_QWORD *)(a1 + 19448) <= (__int64)(unsigned int)v11 )
        v8 = v11;
      else
        v8 = *(_QWORD *)(a1 + 19448);
      v6 = v7;
      v7 = v8;
    }
    else
    {
      v8 = v7;
    }
    v3 = (_QWORD *)*v3;
    ++v5;
    v4 = v9;
  }
  while ( *v9 != a1 + 3208 );
  result = 0;
  v17 = v8;
  if ( v5 >= 3 && v8 == v6 )
  {
    v12 = *(_DWORD *)(a1 + 38696);
    if ( v8 != v12 )
    {
      v13 = a1;
      if ( a1 )
      {
        if ( (msm_vidc_debug & 4) != 0 )
        {
          printk(&unk_884A6, "low ", a1 + 340, "msm_vidc_set_auto_framerate", HIWORD(v12));
          v13 = a1;
        }
        result = venus_hfi_session_property(v13, 50331916, 0, 1, 8, &v17, 4);
        if ( (_DWORD)result )
        {
          if ( (msm_vidc_debug & 1) != 0 )
          {
            v15 = a1 + 340;
            v16 = result;
            printk(&unk_8BFC8, "err ", v15, "msm_vidc_set_auto_framerate", v14);
            result = v16;
          }
          goto LABEL_5;
        }
      }
      else
      {
        result = venus_hfi_session_property(0, 50331916, 0, 1, 8, &v17, 4);
        if ( (_DWORD)result )
          goto LABEL_5;
      }
      result = 0;
      *(_DWORD *)(a1 + 38696) = v17;
      goto LABEL_5;
    }
LABEL_4:
    result = 0;
  }
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
