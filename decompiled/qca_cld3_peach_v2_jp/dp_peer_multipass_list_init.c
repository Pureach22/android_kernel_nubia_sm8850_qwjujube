__int64 __fastcall dp_peer_multipass_list_init(__int64 result)
{
  *(_QWORD *)(result + 42472) = 0;
  *(_DWORD *)(result + 42488) = 0;
  *(_QWORD *)(result + 42480) = result + 42472;
  *(_QWORD *)(result + 42496) = 0;
  return result;
}
