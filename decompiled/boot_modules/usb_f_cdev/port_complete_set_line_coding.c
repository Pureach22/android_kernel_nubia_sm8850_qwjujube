__int64 *__fastcall port_complete_set_line_coding(__int64 *result, _DWORD *a2)
{
  __int64 v2; // x9
  int v3; // w8

  if ( !a2[21] )
  {
    if ( a2[22] == 7 )
    {
      v2 = *result;
      v3 = **(_DWORD **)a2;
      *(_DWORD *)(v2 + 1459) = *(_DWORD *)(*(_QWORD *)a2 + 3LL);
      *(_DWORD *)(v2 + 1456) = v3;
    }
    else
    {
      return (__int64 *)usb_ep_set_halt(result, a2);
    }
  }
  return result;
}
