void *__fastcall sde_cp_duplicate_state_info(
        void *result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int a8)
{
  char v9; // [xsp+0h] [xbp+0h]

  if ( result )
  {
    if ( a2 )
    {
      sde_evtlog_log(sde_dbg_base_evtlog, "sde_cp_duplicate_state_info", 5437, -1, a2, (int)result, -1059143953, a8, v9);
      *(_QWORD *)(a2 + 6064) = 0;
      *(_QWORD *)(a2 + 6056) = 0;
      *(_QWORD *)(a2 + 6048) = 0;
      *(_QWORD *)(a2 + 6040) = 0;
      *(_QWORD *)(a2 + 6032) = 0;
      *(_QWORD *)(a2 + 6024) = 0;
      *(_QWORD *)(a2 + 6016) = 0;
      *(_QWORD *)(a2 + 6008) = 0;
      *(_QWORD *)(a2 + 6000) = 0;
      *(_QWORD *)(a2 + 5992) = 0;
      *(_QWORD *)(a2 + 5984) = 0;
      *(_QWORD *)(a2 + 5976) = 0;
      *(_QWORD *)(a2 + 5968) = 0;
      *(_QWORD *)(a2 + 5960) = 0;
      *(_QWORD *)(a2 + 5952) = 0;
      *(_QWORD *)(a2 + 5944) = 0;
      *(_QWORD *)(a2 + 5936) = 0;
      *(_QWORD *)(a2 + 5928) = 0;
      *(_QWORD *)(a2 + 5920) = 0;
      *(_QWORD *)(a2 + 5912) = 0;
      *(_QWORD *)(a2 + 5904) = 0;
      *(_QWORD *)(a2 + 5896) = 0;
      *(_QWORD *)(a2 + 5888) = 0;
      *(_QWORD *)(a2 + 5880) = 0;
      *(_QWORD *)(a2 + 5872) = 0;
      *(_QWORD *)(a2 + 5864) = 0;
      memset((void *)(a2 + 4616), 0, 0x4E0u);
      result = memset((void *)(a2 + 6072), 0, 0x340u);
      *(_DWORD *)(a2 + 4608) = 0;
    }
  }
  return result;
}
