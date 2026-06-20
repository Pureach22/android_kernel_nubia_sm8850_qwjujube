__int64 __fastcall save_fw_version_cmd_tlv(__int64 a1, __int64 a2)
{
  if ( !*(_QWORD *)a2 )
    return 16;
  qdf_mem_copy((void *)(a1 + 272), (const void *)(*(_QWORD *)a2 + 8LL), 0x18u);
  return 0;
}
