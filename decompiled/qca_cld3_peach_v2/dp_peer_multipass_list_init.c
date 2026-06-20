__int64 __fastcall dp_peer_multipass_list_init(__int64 result)
{
  *(_QWORD *)(result + 43296) = 0;
  *(_DWORD *)(result + 43312) = 0;
  *(_QWORD *)(result + 43304) = result + 43296;
  *(_QWORD *)(result + 43320) = 0;
  return result;
}
