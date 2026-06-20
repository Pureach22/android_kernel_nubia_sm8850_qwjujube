__int64 __fastcall sde_sync_get(int a1)
{
  if ( a1 < 0 )
    return 0;
  else
    return sync_file_get_fence();
}
