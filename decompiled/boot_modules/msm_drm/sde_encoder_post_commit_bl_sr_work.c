__int64 __fastcall sde_encoder_post_commit_bl_sr_work(__int64 result)
{
  if ( result )
  {
    if ( *(_DWORD *)(result + 4912) )
      *(_DWORD *)(result + 4912) = 2;
    return kthread_cancel_delayed_work_sync(result + 1224);
  }
  return result;
}
