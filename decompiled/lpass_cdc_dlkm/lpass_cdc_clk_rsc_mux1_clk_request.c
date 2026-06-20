__int64 __fastcall lpass_cdc_clk_rsc_mux1_clk_request(_QWORD *a1, int a2, char a3)
{
  __int64 v5; // x24
  __int64 v6; // x19
  char v7; // w23
  __int64 v8; // x22
  _BOOL4 v9; // w26
  __int64 result; // x0
  _QWORD *v11; // x25
  int v12; // w8
  int v13; // w8
  __int64 v14; // x23
  unsigned int v15; // w28
  unsigned int v16; // w21
  int v17; // w8
  int v18; // w8
  __int64 v19; // x19
  unsigned int v20; // w20
  unsigned int v21; // w0
  unsigned int v22; // w26
  __int64 v23; // x22
  int v24; // w8
  int v25; // w8
  __int64 v26; // x19
  unsigned int v27; // w22
  unsigned int v28; // w21

  if ( (unsigned int)a2 >= 8 )
    goto LABEL_64;
  v5 = a2;
  v6 = *((int *)a1 + a2 + 56);
  if ( a2 <= 2 )
  {
    if ( a2 == 1 )
    {
      v8 = a1[33];
      goto LABEL_12;
    }
    if ( a2 != 2 )
      goto LABEL_5;
LABEL_10:
    v8 = a1[34];
    goto LABEL_12;
  }
  if ( a2 == 3 )
  {
    v8 = a1[35];
    v9 = 0;
    goto LABEL_16;
  }
  if ( a2 == 4 )
    goto LABEL_10;
LABEL_5:
  v7 = a3;
  if ( (unsigned int)__ratelimit(&lpass_cdc_clk_rsc_get_clk_muxsel__rs, "lpass_cdc_clk_rsc_get_clk_muxsel") )
    dev_err(*a1, "%s: Invalid case\n", "lpass_cdc_clk_rsc_get_clk_muxsel");
  v8 = 0;
  a3 = v7;
LABEL_12:
  v9 = a2 != 3;
  if ( a2 != 3 && !v8 )
    return 4294967274LL;
LABEL_16:
  v11 = a1 + 21;
  v12 = *((_DWORD *)a1 + v5 + 42);
  if ( (a3 & 1) != 0 )
  {
    if ( v12 )
    {
      result = 0;
LABEL_19:
      ++*((_DWORD *)v11 + v5);
      return result;
    }
    if ( !v9
      || (result = ((__int64 (__fastcall *)(_QWORD *, _QWORD, __int64))lpass_cdc_clk_rsc_mux0_clk_request)(
                     a1,
                     (unsigned int)v6,
                     1),
          (result & 0x80000000) == 0) )
    {
      v14 = a1[v5 + 13];
      result = clk_prepare(v14);
      if ( !(_DWORD)result )
      {
        result = clk_enable(v14);
        if ( !(_DWORD)result )
        {
LABEL_29:
          if ( !v9 )
            goto LABEL_19;
          if ( *((_BYTE *)a1 + 209) == 1 )
          {
            v16 = result;
            writel_0(1, v8);
            readl_0(v8);
            result = v16;
          }
          if ( (unsigned int)v6 < 8 )
          {
            v17 = *((_DWORD *)v11 + v6);
            if ( v17 <= 0 )
            {
              v28 = result;
              if ( (unsigned int)__ratelimit(
                                   &lpass_cdc_clk_rsc_mux0_clk_request__rs_13,
                                   "lpass_cdc_clk_rsc_mux0_clk_request") )
                dev_err(*a1, "%s: clk_id: %d is already disabled\n", "lpass_cdc_clk_rsc_mux0_clk_request", v6);
              *((_DWORD *)v11 + v6) = 0;
              result = v28;
            }
            else
            {
              v18 = v17 - 1;
              *((_DWORD *)v11 + v6) = v18;
              if ( !v18 )
              {
                v19 = a1[v6 + 13];
                v20 = result;
                clk_disable(v19);
                clk_unprepare(v19);
                result = v20;
              }
            }
            goto LABEL_19;
          }
LABEL_64:
          __break(0x5512u);
          JUMPOUT(0xC7E0);
        }
        v15 = result;
        clk_unprepare(v14);
        result = v15;
      }
      if ( (result & 0x80000000) == 0 )
        goto LABEL_29;
      v27 = result;
      if ( (unsigned int)__ratelimit(&lpass_cdc_clk_rsc_mux1_clk_request__rs, "lpass_cdc_clk_rsc_mux1_clk_request") )
      {
        dev_err(*a1, "%s:clk_id %d enable failed\n", "lpass_cdc_clk_rsc_mux1_clk_request", a2);
        if ( !v9 )
          return v27;
      }
      else if ( !v9 )
      {
        return v27;
      }
      ((void (__fastcall *)(_QWORD *, _QWORD, _QWORD))lpass_cdc_clk_rsc_mux0_clk_request)(a1, (unsigned int)v6, 0);
      return v27;
    }
    return result;
  }
  if ( v12 <= 0 )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_clk_rsc_mux1_clk_request__rs_10, "lpass_cdc_clk_rsc_mux1_clk_request") )
      dev_err(*a1, "%s: clk_id: %d is already disabled\n", "lpass_cdc_clk_rsc_mux1_clk_request", a2);
    *((_DWORD *)v11 + v5) = 0;
    return 0;
  }
  v13 = v12 - 1;
  *((_DWORD *)v11 + v5) = v13;
  if ( v13 )
    return 0;
  if ( v9 )
  {
    v21 = ((__int64 (__fastcall *)(_QWORD *, _QWORD, __int64))lpass_cdc_clk_rsc_mux0_clk_request)(
            a1,
            (unsigned int)v6,
            1);
    if ( v21 )
      goto LABEL_44;
    if ( *((_BYTE *)a1 + 209) == 1 )
    {
      writel_0(0, v8);
      readl_0(v8);
    }
  }
  v21 = 0;
LABEL_44:
  v22 = v21;
  v23 = a1[v5 + 13];
  clk_disable(v23);
  clk_unprepare(v23);
  if ( a2 == 3 )
    return v22;
  result = v22;
  if ( !v22 )
  {
    if ( (unsigned int)v6 >= 8 )
      goto LABEL_64;
    v24 = *((_DWORD *)v11 + v6);
    if ( v24 <= 0 )
    {
      if ( (unsigned int)__ratelimit(&lpass_cdc_clk_rsc_mux0_clk_request__rs_13, "lpass_cdc_clk_rsc_mux0_clk_request") )
        dev_err(*a1, "%s: clk_id: %d is already disabled\n", "lpass_cdc_clk_rsc_mux0_clk_request", v6);
      result = 0;
      *((_DWORD *)v11 + v6) = 0;
      return result;
    }
    v25 = v24 - 1;
    *((_DWORD *)v11 + v6) = v25;
    if ( !v25 )
    {
      v26 = a1[v6 + 13];
      clk_disable(v26);
      clk_unprepare(v26);
    }
    return 0;
  }
  return result;
}
