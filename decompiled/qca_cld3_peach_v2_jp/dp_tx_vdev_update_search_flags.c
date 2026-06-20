__int64 __fastcall dp_tx_vdev_update_search_flags(__int64 result)
{
  char v1; // w9
  __int64 v2; // x8

  if ( *(_DWORD *)(result + 32) != 3 )
  {
    v1 = 1;
    goto LABEL_5;
  }
  if ( *(_BYTE *)(result + 320) == 1 )
  {
    v1 = 3;
LABEL_5:
    *(_BYTE *)(result + 81) = v1;
    *(_BYTE *)(result + 73) = 0;
    return result;
  }
  v2 = *(_QWORD *)(*(_QWORD *)(result + 24) + 8LL);
  *(_BYTE *)(result + 81) = 2;
  *(_BYTE *)(result + 73) = *(_BYTE *)(v2 + 17657);
  return result;
}
