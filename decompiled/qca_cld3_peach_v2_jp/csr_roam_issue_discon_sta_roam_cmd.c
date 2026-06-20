__int64 __fastcall csr_roam_issue_discon_sta_roam_cmd(__int64 a1, __int64 a2, unsigned int a3, unsigned int *a4)
{
  unsigned __int8 v6; // w20
  __int64 v8; // x8
  __int64 v9; // x9
  char is_deauth_disassoc_cmd_active; // w8
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 result; // x0
  __int64 command_buffer; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  int v29; // w8
  unsigned __int16 v30; // w9
  int v31; // w8
  __int16 v32; // w9
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x5
  __int64 v42; // x6
  __int64 v43; // x7
  int v44; // w8
  __int64 v45; // x6
  __int64 v46; // x7
  int v47; // w8
  int v48; // w9
  __int64 v49; // x5
  __int64 v50; // x6
  __int64 v51; // x7
  int v52; // w8
  unsigned int v53; // w19
  int v54; // [xsp+10h] [xbp-20h] BYREF
  __int16 v55; // [xsp+14h] [xbp-1Ch]
  int v56; // [xsp+18h] [xbp-18h] BYREF
  unsigned __int16 v57; // [xsp+1Ch] [xbp-14h]
  __int64 v58; // [xsp+28h] [xbp-8h]

  v6 = a2;
  v58 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *((unsigned __int16 *)a4 + 2);
  v9 = *a4;
  v57 = 0;
  v56 = 0;
  v55 = 0;
  v54 = 0;
  is_deauth_disassoc_cmd_active = csr_is_deauth_disassoc_cmd_active(a1, a2, v9 | (v8 << 32), &v56, &v54);
  result = 0;
  if ( (is_deauth_disassoc_cmd_active & 1) == 0 )
  {
    if ( v56 | v57 )
    {
      command_buffer = sme_get_command_buffer(a1);
      if ( command_buffer )
      {
        ++*(_DWORD *)(a1 + 17220);
        *(_DWORD *)(command_buffer + 16) = 65537;
        v29 = v56;
        v30 = v57;
        *(_DWORD *)(command_buffer + 24) = v6;
        *(_DWORD *)(command_buffer + 32) = a3;
        *(_DWORD *)(command_buffer + 36) = v29;
        v31 = v54;
        *(_WORD *)(command_buffer + 40) = v30;
        v32 = v55;
        *(_DWORD *)(command_buffer + 42) = v31;
        *(_WORD *)(command_buffer + 46) = v32;
        *(_DWORD *)(command_buffer + 48) = *((unsigned __int16 *)a4 + 6);
        result = csr_queue_sme_command(a1, command_buffer, 0);
        if ( (_DWORD)result )
        {
          if ( a4 )
          {
            v41 = *(unsigned __int8 *)a4;
            v42 = *((unsigned __int8 *)a4 + 1);
            v43 = *((unsigned __int8 *)a4 + 2);
            v44 = *((unsigned __int8 *)a4 + 5);
          }
          else
          {
            v43 = 0;
            v41 = 0;
            v42 = 0;
            v44 = 0;
          }
          v53 = result;
          qdf_trace_msg(
            0x34u,
            2u,
            "%s: Vdev %d %02x:%02x:%02x:**:**:%02x fails to get send message status: %d",
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            "csr_roam_issue_discon_sta_roam_cmd",
            v6,
            v41,
            v42,
            v43,
            v44,
            result);
          result = v53;
        }
      }
      else
      {
        if ( a4 )
        {
          v49 = *(unsigned __int8 *)a4;
          v50 = *((unsigned __int8 *)a4 + 1);
          v51 = *((unsigned __int8 *)a4 + 2);
          v52 = *((unsigned __int8 *)a4 + 5);
        }
        else
        {
          v51 = 0;
          v49 = 0;
          v50 = 0;
          v52 = 0;
        }
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: Vdev %d %02x:%02x:%02x:**:**:%02x fails to get command buffer for reason %d",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "csr_roam_issue_discon_sta_roam_cmd",
          v6,
          v49,
          v50,
          v51,
          v52,
          a3);
        result = 1;
      }
    }
    else
    {
      if ( a4 )
      {
        v45 = *(unsigned __int8 *)a4;
        v46 = *((unsigned __int8 *)a4 + 1);
        v47 = *((unsigned __int8 *)a4 + 2);
        v48 = *((unsigned __int8 *)a4 + 5);
      }
      else
      {
        v47 = 0;
        v45 = 0;
        v46 = 0;
        v48 = 0;
      }
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: Vdev %d reason %d %02x:%02x:%02x:**:**:%02x fails to find peer, already disconnected!!",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "csr_roam_issue_discon_sta_roam_cmd",
        v6,
        a3,
        v45,
        v46,
        v47,
        v48);
      result = 6;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
