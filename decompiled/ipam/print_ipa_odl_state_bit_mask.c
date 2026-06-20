void print_ipa_odl_state_bit_mask()
{
  __int64 v0; // x8
  __int64 v1; // x0
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0

  v0 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v1 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v1 )
    {
      ipc_log_string(
        v1,
        "ipa %s:%d ipa3_odl_ctx->odl_state.odl_init --> %d\n",
        "print_ipa_odl_state_bit_mask",
        20,
        *(_WORD *)(ipa3_odl_ctx + 692) & 1);
      v0 = ipa3_ctx;
    }
    v2 = *(_QWORD *)(v0 + 34160);
    if ( v2 )
    {
      ipc_log_string(
        v2,
        "ipa %s:%d ipa3_odl_ctx->odl_state.odl_init --> %d\n",
        "print_ipa_odl_state_bit_mask",
        20,
        *(_WORD *)(ipa3_odl_ctx + 692) & 1);
      v0 = ipa3_ctx;
    }
    if ( v0 )
    {
      v3 = *(_QWORD *)(v0 + 34152);
      if ( v3 )
      {
        ipc_log_string(
          v3,
          "ipa %s:%d ipa3_odl_ctx->odl_state.odl_open --> %d\n",
          "print_ipa_odl_state_bit_mask",
          22,
          (*(unsigned __int16 *)(ipa3_odl_ctx + 692) >> 1) & 1);
        v0 = ipa3_ctx;
      }
      v4 = *(_QWORD *)(v0 + 34160);
      if ( v4 )
      {
        ipc_log_string(
          v4,
          "ipa %s:%d ipa3_odl_ctx->odl_state.odl_open --> %d\n",
          "print_ipa_odl_state_bit_mask",
          22,
          (*(unsigned __int16 *)(ipa3_odl_ctx + 692) >> 1) & 1);
        v0 = ipa3_ctx;
      }
      if ( v0 )
      {
        v5 = *(_QWORD *)(v0 + 34152);
        if ( v5 )
        {
          ipc_log_string(
            v5,
            "ipa %s:%d ipa3_odl_ctx->odl_state.adpl_open --> %d\n",
            "print_ipa_odl_state_bit_mask",
            24,
            (*(unsigned __int16 *)(ipa3_odl_ctx + 692) >> 2) & 1);
          v0 = ipa3_ctx;
        }
        v6 = *(_QWORD *)(v0 + 34160);
        if ( v6 )
        {
          ipc_log_string(
            v6,
            "ipa %s:%d ipa3_odl_ctx->odl_state.adpl_open --> %d\n",
            "print_ipa_odl_state_bit_mask",
            24,
            (*(unsigned __int16 *)(ipa3_odl_ctx + 692) >> 2) & 1);
          v0 = ipa3_ctx;
        }
        if ( v0 )
        {
          v7 = *(_QWORD *)(v0 + 34152);
          if ( v7 )
          {
            ipc_log_string(
              v7,
              "ipa %s:%d ipa3_odl_ctx->odl_state.aggr_byte_limit_sent --> %d\n",
              "print_ipa_odl_state_bit_mask",
              26,
              (*(unsigned __int16 *)(ipa3_odl_ctx + 692) >> 3) & 1);
            v0 = ipa3_ctx;
          }
          v8 = *(_QWORD *)(v0 + 34160);
          if ( v8 )
          {
            ipc_log_string(
              v8,
              "ipa %s:%d ipa3_odl_ctx->odl_state.aggr_byte_limit_sent --> %d\n",
              "print_ipa_odl_state_bit_mask",
              26,
              (*(unsigned __int16 *)(ipa3_odl_ctx + 692) >> 3) & 1);
            v0 = ipa3_ctx;
          }
          if ( v0 )
          {
            v9 = *(_QWORD *)(v0 + 34152);
            if ( v9 )
            {
              ipc_log_string(
                v9,
                "ipa %s:%d ipa3_odl_ctx->odl_state.odl_ep_setup --> %d\n",
                "print_ipa_odl_state_bit_mask",
                28,
                (*(unsigned __int16 *)(ipa3_odl_ctx + 692) >> 4) & 1);
              v0 = ipa3_ctx;
            }
            v10 = *(_QWORD *)(v0 + 34160);
            if ( v10 )
            {
              ipc_log_string(
                v10,
                "ipa %s:%d ipa3_odl_ctx->odl_state.odl_ep_setup --> %d\n",
                "print_ipa_odl_state_bit_mask",
                28,
                (*(unsigned __int16 *)(ipa3_odl_ctx + 692) >> 4) & 1);
              v0 = ipa3_ctx;
            }
            if ( v0 )
            {
              v11 = *(_QWORD *)(v0 + 34152);
              if ( v11 )
              {
                ipc_log_string(
                  v11,
                  "ipa %s:%d ipa3_odl_ctx->odl_state.odl_setup_done_sent --> %d\n",
                  "print_ipa_odl_state_bit_mask",
                  30,
                  (*(unsigned __int16 *)(ipa3_odl_ctx + 692) >> 5) & 1);
                v0 = ipa3_ctx;
              }
              v12 = *(_QWORD *)(v0 + 34160);
              if ( v12 )
              {
                ipc_log_string(
                  v12,
                  "ipa %s:%d ipa3_odl_ctx->odl_state.odl_setup_done_sent --> %d\n",
                  "print_ipa_odl_state_bit_mask",
                  30,
                  (*(unsigned __int16 *)(ipa3_odl_ctx + 692) >> 5) & 1);
                v0 = ipa3_ctx;
              }
              if ( v0 )
              {
                v13 = *(_QWORD *)(v0 + 34152);
                if ( v13 )
                {
                  ipc_log_string(
                    v13,
                    "ipa %s:%d ipa3_odl_ctx->odl_state.odl_ep_info_sent --> %d\n",
                    "print_ipa_odl_state_bit_mask",
                    32,
                    (*(unsigned __int16 *)(ipa3_odl_ctx + 692) >> 6) & 1);
                  v0 = ipa3_ctx;
                }
                v14 = *(_QWORD *)(v0 + 34160);
                if ( v14 )
                {
                  ipc_log_string(
                    v14,
                    "ipa %s:%d ipa3_odl_ctx->odl_state.odl_ep_info_sent --> %d\n",
                    "print_ipa_odl_state_bit_mask",
                    32,
                    (*(unsigned __int16 *)(ipa3_odl_ctx + 692) >> 6) & 1);
                  v0 = ipa3_ctx;
                }
                if ( v0 )
                {
                  v15 = *(_QWORD *)(v0 + 34152);
                  if ( v15 )
                  {
                    ipc_log_string(
                      v15,
                      "ipa %s:%d ipa3_odl_ctx->odl_state.odl_connected --> %d\n",
                      "print_ipa_odl_state_bit_mask",
                      34,
                      (*(unsigned __int16 *)(ipa3_odl_ctx + 692) >> 7) & 1);
                    v0 = ipa3_ctx;
                  }
                  v16 = *(_QWORD *)(v0 + 34160);
                  if ( v16 )
                  {
                    ipc_log_string(
                      v16,
                      "ipa %s:%d ipa3_odl_ctx->odl_state.odl_connected --> %d\n",
                      "print_ipa_odl_state_bit_mask",
                      34,
                      (*(unsigned __int16 *)(ipa3_odl_ctx + 692) >> 7) & 1);
                    v0 = ipa3_ctx;
                  }
                  if ( v0 )
                  {
                    v17 = *(_QWORD *)(v0 + 34152);
                    if ( v17 )
                    {
                      ipc_log_string(
                        v17,
                        "ipa %s:%d ipa3_odl_ctx->odl_state.odl_disconnected --> %d\n\n",
                        "print_ipa_odl_state_bit_mask",
                        36,
                        HIBYTE(*(unsigned __int16 *)(ipa3_odl_ctx + 692)) & 1);
                      v0 = ipa3_ctx;
                    }
                    v18 = *(_QWORD *)(v0 + 34160);
                    if ( v18 )
                      ipc_log_string(
                        v18,
                        "ipa %s:%d ipa3_odl_ctx->odl_state.odl_disconnected --> %d\n\n",
                        "print_ipa_odl_state_bit_mask",
                        36,
                        HIBYTE(*(unsigned __int16 *)(ipa3_odl_ctx + 692)) & 1);
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
