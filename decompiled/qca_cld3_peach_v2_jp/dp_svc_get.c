__int64 __fastcall dp_svc_get(unsigned __int8 a1, __int64 a2, unsigned __int16 a3)
{
  __int64 context; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x8
  unsigned __int64 StatusReg; // x9
  unsigned int v17; // w10
  unsigned int v18; // w20
  __int64 v19; // x8
  __int64 v20; // x9
  unsigned int v21; // w11
  __int64 v22; // x12
  unsigned int v23; // w13
  __int64 v24; // x11

  context = dp_get_context();
  if ( context && (v15 = *(_QWORD *)(context + 1552)) != 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    *(_DWORD *)(StatusReg + 16) += 512;
    if ( a1 == 0xFF )
    {
      v20 = 0;
      v21 = 0;
      do
      {
        v22 = *(_QWORD *)(v15 + v20);
        if ( v22 )
        {
          v23 = v21 + 1;
          if ( v21 + 1 < a3 )
          {
            v24 = a2 + 32LL * v21;
            *(_BYTE *)(v24 + 16) = *(_BYTE *)(v22 + 16);
            *(_DWORD *)(v24 + 20) = *(_DWORD *)(v22 + 20);
            *(_BYTE *)(v24 + 24) = *(_BYTE *)(v22 + 24);
            *(_BYTE *)(v24 + 25) = *(_BYTE *)(v22 + 25);
            *(_DWORD *)(v24 + 28) = *(_DWORD *)(v22 + 28);
            v21 = v23;
          }
        }
        v20 += 8;
      }
      while ( v20 != 256 );
      v18 = (unsigned __int8)v21;
    }
    else if ( a1 > 0x1Fu )
    {
      v18 = 0;
    }
    else
    {
      v17 = a3;
      v18 = 0;
      v19 = *(_QWORD *)(v15 + 8LL * a1);
      if ( v17 >= 2 && v19 )
      {
        v18 = 1;
        *(_BYTE *)(a2 + 16) = *(_BYTE *)(v19 + 16);
        *(_DWORD *)(a2 + 20) = *(_DWORD *)(v19 + 20);
        *(_BYTE *)(a2 + 24) = *(_BYTE *)(v19 + 24);
        *(_BYTE *)(a2 + 25) = *(_BYTE *)(v19 + 25);
        *(_DWORD *)(a2 + 28) = *(_DWORD *)(v19 + 28);
      }
    }
    local_bh_enable_5();
  }
  else
  {
    qdf_trace_msg(0x45u, 2u, "%s: svc_ctx is not initialised", v7, v8, v9, v10, v11, v12, v13, v14, "dp_svc_get");
    return 0;
  }
  return v18;
}
