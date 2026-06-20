__int64 __fastcall icnss_send_smp2p(__int64 a1, int a2, unsigned int a3)
{
  char *v3; // x20
  unsigned int v4; // w22
  int v5; // w23
  __int64 v6; // x24
  __int64 v7; // x8
  __int64 v8; // x21
  unsigned __int64 v9; // x8
  __int64 v10; // x8
  __int64 v12; // x8
  char *v13; // x19
  __int64 v14; // x0
  int v15; // w0
  int v16; // w8
  const char *v17; // x19
  __int64 v18; // x9
  int v19; // w8
  unsigned int updated; // w0
  __int64 v21; // x0
  __int64 v22; // x8
  __int64 v23; // x5
  unsigned int v24; // w0
  const char *v25; // x19
  __int64 v26; // x22
  unsigned __int64 v33; // x10

  if ( !a1 )
    goto LABEL_12;
  v7 = *(_QWORD *)(a1 + 304);
  if ( v7 != 25680 && v7 != 26448 && v7 != 30544 && *(_BYTE *)(a1 + 5968) != 1
    || (LODWORD(v8) = -22, (v9 = *(_QWORD *)(a1 + 16LL * a3 + 3048)) != 0) && v9 <= 0xFFFFFFFFFFFFF000LL )
  {
    if ( a2 )
    {
      v10 = *(_QWORD *)(a1 + 1832);
      if ( (v10 & 0x2000) != 0 || (v10 = *(_QWORD *)(a1 + 1832), (v10 & 4) == 0) )
      {
        ipc_log_string(icnss_ipc_log_smp2p_context, "icnss2: FW down, ignoring sending SMP2P state: 0x%lx\n", v10);
LABEL_12:
        LODWORD(v8) = -22;
        return (unsigned int)v8;
      }
      v18 = a1 + 16LL * a3;
      v3 = "eq %d\n";
      v4 = a3;
      v6 = a1;
      v5 = a2;
      v19 = *(unsigned __int16 *)(v18 + 3040);
      v8 = v18 + 3040;
      LODWORD(v13) = a2 | (v19 << 16);
      *(_WORD *)(v18 + 3040) = v19 + 1;
      ipc_log_string(
        icnss_ipc_log_smp2p_context,
        "icnss2: Sending SMP2P value: 0x%X, Ref count: %d\n",
        (_DWORD)v13,
        *(_DWORD *)(a1 + 5488));
      if ( (v5 & 0xFFFFFFFE) == 4 )
      {
        while ( 1 )
        {
          _X8 = (unsigned __int64 *)(v6 + 1832);
          __asm { PRFM            #0x11, [X8] }
          do
            v33 = __ldxr(_X8);
          while ( __stxr(v33 & 0xFFFFFFFFF7FFFFFFLL, _X8) );
          *(_DWORD *)(penv + 5808) = 0;
          updated = qcom_smem_state_update_bits(*(_QWORD *)(v8 + 8), 0xFFFFFFFFLL, (unsigned int)v13);
          v8 = updated;
          if ( updated )
          {
LABEL_24:
            if ( v4 <= 2 )
            {
              ipc_log_string(*((_QWORD *)v3 + 56), "icnss2: Error in SMP2P send ret: %d, %s\n", v8, icnss_smp2p_str[v4]);
              return (unsigned int)v8;
            }
          }
          else
          {
            v21 = wait_for_completion_timeout(v6 + 5808, 125);
            v22 = v6;
            if ( v21 )
            {
              v23 = *(_QWORD *)(v6 + 1832);
              if ( (v23 & 0x8000000) != 0 )
                goto LABEL_22;
            }
            else
            {
              if ( v4 > 2 )
                goto LABEL_30;
              v3 = "%sicnss2: SMP2P Soc Wake timeout msg %d, %s, Ref count: %d\n";
              v13 = icnss_smp2p_str[v4];
              printk(
                "%sicnss2: SMP2P Soc Wake timeout msg %d, %s, Ref count: %d\n",
                byte_130B32,
                v5,
                v13,
                *(_DWORD *)(v6 + 5488));
              ipc_log_string(
                icnss_ipc_log_context,
                "%sicnss2: SMP2P Soc Wake timeout msg %d, %s, Ref count: %d\n",
                (const char *)&unk_12DBF3,
                v5,
                v13,
                *(_DWORD *)(v6 + 5488));
              v22 = v6;
              v23 = *(_QWORD *)(v6 + 1832);
              if ( (v23 & 0x8000000) != 0 )
              {
LABEL_22:
                LODWORD(v8) = 0;
                return (unsigned int)v8;
              }
            }
            if ( v4 <= 2 )
            {
              v25 = icnss_smp2p_str[v4];
              v26 = v22;
              printk(
                "%sicnss2: SMP2P Soc Wake timeout msg %d, %s, Ref count: %d, state: 0x%lx\n",
                byte_130B32,
                v5,
                v25,
                *(_DWORD *)(v22 + 5488),
                v23);
              ipc_log_string(
                icnss_ipc_log_context,
                "%sicnss2: SMP2P Soc Wake timeout msg %d, %s, Ref count: %d, state: 0x%lx\n",
                (const char *)&unk_12DBF3,
                v5,
                v25,
                *(_DWORD *)(v26 + 5488),
                *(_QWORD *)(v26 + 1832));
              LODWORD(v8) = -110;
              return (unsigned int)v8;
            }
          }
LABEL_30:
          __break(1u);
        }
      }
      v24 = qcom_smem_state_update_bits(*(_QWORD *)(v8 + 8), 0xFFFFFFFFLL, (unsigned int)v13);
      v8 = v24;
      if ( v24 )
        goto LABEL_24;
    }
    else
    {
      v12 = a1 + 16LL * a3;
      LODWORD(v13) = a3;
      v14 = *(_QWORD *)(v12 + 3048);
      *(_WORD *)(v12 + 3040) = 0;
      v15 = qcom_smem_state_update_bits(v14, 0xFFFFFFFFLL, 0);
      v8 = 0;
      if ( v15 )
      {
        v16 = (int)v13;
        if ( (unsigned int)v13 > 2 )
          goto LABEL_30;
        LODWORD(v8) = v15;
        v17 = icnss_smp2p_str[(unsigned int)v13];
        printk("%sicnss2: Error in SMP2P sent. ret: %d, %s\n", byte_130B32, v15, icnss_smp2p_str[v16]);
        ipc_log_string(
          icnss_ipc_log_context,
          "%sicnss2: Error in SMP2P sent. ret: %d, %s\n",
          (const char *)&unk_12DBF3,
          v8,
          v17);
      }
    }
  }
  return (unsigned int)v8;
}
