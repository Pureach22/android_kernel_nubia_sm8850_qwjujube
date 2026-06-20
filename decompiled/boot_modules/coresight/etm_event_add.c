__int64 __fastcall etm_event_add(__int64 a1, char a2)
{
  if ( (a2 & 1) != 0 )
  {
    etm_event_start(a1);
    return (*(unsigned __int8 *)(a1 + 480) << 31 >> 31) & 0xFFFFFFEA;
  }
  else
  {
    *(_DWORD *)(a1 + 480) = 1;
    return 0;
  }
}
