__int64 __fastcall synx_custom_get_status(unsigned __int64 a1, unsigned int a2)
{
  int status; // w21

  if ( a1 )
  {
    if ( (*(_BYTE *)(a1 + 124) & 2) != 0 )
    {
      status = synx_global_get_status(*(unsigned int *)(a1 + 344));
      if ( a1 > 0xFFFFFFFFFFFFF000LL )
        return a2;
    }
    else
    {
      status = 1;
      if ( a1 > 0xFFFFFFFFFFFFF000LL )
        return a2;
    }
    mutex_lock(a1 + 72);
    if ( (*(_BYTE *)(a1 + 124) & 0x20) != 0 )
    {
      if ( status == 1 )
        status = synx_get_child_status(a1);
      a2 = status;
      *(_DWORD *)(a1 + 128) = status;
    }
    mutex_unlock(a1 + 72);
  }
  return a2;
}
