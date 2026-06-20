__int64 __fastcall hdcp1_stop_qseecom(__int64 result)
{
  if ( !result || !*(_QWORD *)result || !*(_QWORD *)(result + 8) )
    return printk(&unk_C81E);
  if ( (*(_BYTE *)(result + 24) & 1) != 0 )
    return hdcp1_app_unload(result);
  return result;
}
