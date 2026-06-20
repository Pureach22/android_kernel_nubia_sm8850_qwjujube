__int64 __fastcall fastrpc_device_release(__int64 a1, __int64 a2)
{
  fastrpc_file_put(*(__int64 **)(a2 + 32), 0);
  *(_QWORD *)(a2 + 32) = 0;
  return 0;
}
