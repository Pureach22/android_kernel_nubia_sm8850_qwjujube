__int64 __fastcall ipa3_cfg_ep(__int64 a1, __int64 a2)
{
  unsigned int v2; // w19
  __int64 result; // x0
  __int64 v5; // x8
  unsigned int v6; // w8
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0

  if ( *(_DWORD *)(ipa3_ctx + 34308) <= (unsigned int)a1 )
    goto LABEL_23;
  v2 = a1;
  if ( (unsigned int)a1 >= 0x24 )
  {
    __break(0x5512u);
    return ipa3_cfg_ep_hdr(a1, a2);
  }
  if ( a2 && *(_DWORD *)(ipa3_ctx + 480LL * (unsigned int)a1 + 168) )
  {
    result = ipa3_cfg_ep_hdr((unsigned int)a1, a2 + 12);
    if ( !(_DWORD)result )
    {
      result = ipa3_cfg_ep_hdr_ext(v2, a2 + 48);
      if ( !(_DWORD)result )
      {
        result = ipa3_cfg_ep_aggr(v2, a2 + 96);
        if ( !(_DWORD)result )
        {
          result = ipa3_cfg_ep_cfg(v2, a2 + 148);
          if ( !(_DWORD)result )
          {
            v5 = ipa3_ctx;
            if ( ipa3_ctx && *(_BYTE *)(ipa3_ctx + 51097) == 1 )
            {
              result = ipa3_cfg_ep_ulso(v2, a2 + 176);
              if ( (_DWORD)result )
                return result;
              v5 = ipa3_ctx;
            }
            v6 = *(_DWORD *)(v5 + 480LL * v2 + 172);
            if ( v6 > 0x85 || (v6 & 1) != 0 )
            {
              result = ipa3_cfg_ep_metadata_mask(v2, a2 + 160);
              if ( !(_DWORD)result )
              {
                if ( *(_DWORD *)(ipa3_ctx + 32240) < 0x18u )
                  return 0;
                result = ipa3_cfg_ep_prod_cfg(v2, a2 + 184);
                if ( !(_DWORD)result )
                  return 0;
              }
            }
            else
            {
              result = ipa3_cfg_ep_nat(v2, a2);
              if ( !(_DWORD)result )
              {
                if ( *(_DWORD *)(ipa3_ctx + 32240) < 0xEu
                  || (result = ipa3_cfg_ep_conn_track(v2, a2 + 8), !(_DWORD)result) )
                {
                  result = ipa3_cfg_ep_mode(v2, a2 + 88);
                  if ( !(_DWORD)result )
                  {
                    result = ipa3_cfg_ep_seq(v2, (_BYTE *)(a2 + 168));
                    if ( !(_DWORD)result )
                    {
                      result = ipa3_cfg_ep_route(v2, a2 + 144);
                      if ( !(_DWORD)result )
                      {
                        result = ipa3_cfg_ep_deaggr(v2, a2 + 124);
                        if ( !(_DWORD)result )
                          return 0;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  else
  {
LABEL_23:
    printk(&unk_3F1C1D, "ipa3_cfg_ep");
    v7 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v8 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v8 )
      {
        ipc_log_string(v8, "ipa %s:%d bad parm.\n", "ipa3_cfg_ep", 8753);
        v7 = ipa3_ctx;
      }
      v9 = *(_QWORD *)(v7 + 34160);
      if ( v9 )
        ipc_log_string(v9, "ipa %s:%d bad parm.\n", "ipa3_cfg_ep", 8753);
    }
    return 4294967274LL;
  }
  return result;
}
