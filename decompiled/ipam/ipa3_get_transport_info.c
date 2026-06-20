__int64 __fastcall ipa3_get_transport_info(_QWORD *a1, _QWORD *a2)
{
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0

  if ( a1 && a2 )
  {
    *a1 = (unsigned int)dword_1F7DB4;
    *a2 = (unsigned int)dword_1F7DB8;
    return 0;
  }
  else
  {
    printk(&unk_3C00ED, "ipa3_get_transport_info");
    v6 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v7 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v7 )
      {
        ipc_log_string(
          v7,
          "ipa %s:%d Bad arg: phys_addr_ptr(%pK) and/or size_ptr(%pK)\n",
          "ipa3_get_transport_info",
          12534,
          a1,
          a2);
        v6 = ipa3_ctx;
      }
      v8 = *(_QWORD *)(v6 + 34160);
      if ( v8 )
        ipc_log_string(
          v8,
          "ipa %s:%d Bad arg: phys_addr_ptr(%pK) and/or size_ptr(%pK)\n",
          "ipa3_get_transport_info",
          12534,
          a1,
          a2);
    }
    return 4294967274LL;
  }
}
