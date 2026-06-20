__int64 __fastcall lim_trigger_sta_deletion(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  int v11; // w6
  __int64 result; // x0
  char v16; // w9
  _QWORD v17[3]; // [xsp+8h] [xbp-18h] BYREF

  v17[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v17, 0, 14);
  if ( a2 )
  {
    v11 = *(_DWORD *)(a2 + 8);
    if ( v11 == 17 || v11 == 22 || *(_BYTE *)(a2 + 645) == 1 )
    {
      result = qdf_trace_msg(
                 0x35u,
                 8u,
                 "%s: Deletion is in progress (%d) for peer:%pK in mlmState %d",
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 a11,
                 "lim_trigger_sta_deletion",
                 *(unsigned __int8 *)(a2 + 645),
                 a2 + 338);
    }
    else
    {
      *(_BYTE *)(a2 + 645) = 1;
      *(_DWORD *)(a2 + 24) = 4;
      *(_WORD *)(a2 + 34) = 2;
      qdf_mem_copy(v17, (const void *)(a2 + 338), 6u);
      v16 = *(_BYTE *)(a3 + 8);
      *(_DWORD *)((char *)v17 + 6) = 131076;
      BYTE4(v17[1]) = v16;
      lim_process_mlm_rsp_messages(a1, 1014, v17);
      result = lim_send_sme_disassoc_ind(a1, a2, a3);
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x35u,
               3u,
               "%s: Skip STA deletion (invalid STA)",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "lim_trigger_sta_deletion");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
