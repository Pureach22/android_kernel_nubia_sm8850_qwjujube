__int64 __fastcall ce_tasklet_kill(__int64 result)
{
  _BYTE *v1; // x20
  __int64 v2; // x19

  v1 = (_BYTE *)(result + 24576);
  v2 = result;
  if ( *(_BYTE *)(result + 26492) == 1 )
  {
    *(_BYTE *)(result + 26492) = 0;
    cancel_work_sync(&unk_6CE1B8);
    result = tasklet_kill(v2 + 26448);
  }
  if ( v1[1972] == 1 )
  {
    v1[1972] = 0;
    cancel_work_sync(&unk_6CE1F8);
    result = tasklet_kill(v2 + 26504);
  }
  if ( v1[2028] == 1 )
  {
    v1[2028] = 0;
    cancel_work_sync(&unk_6CE238);
    result = tasklet_kill(v2 + 26560);
  }
  if ( v1[2084] == 1 )
  {
    v1[2084] = 0;
    cancel_work_sync(&unk_6CE278);
    result = tasklet_kill(v2 + 26616);
  }
  if ( v1[2140] == 1 )
  {
    v1[2140] = 0;
    cancel_work_sync(&unk_6CE2B8);
    result = tasklet_kill(v2 + 26672);
  }
  if ( v1[2196] == 1 )
  {
    v1[2196] = 0;
    cancel_work_sync(&unk_6CE2F8);
    result = tasklet_kill(v2 + 26728);
  }
  if ( v1[2252] == 1 )
  {
    v1[2252] = 0;
    cancel_work_sync(&unk_6CE338);
    result = tasklet_kill(v2 + 26784);
  }
  if ( v1[2308] == 1 )
  {
    v1[2308] = 0;
    cancel_work_sync(&unk_6CE378);
    result = tasklet_kill(v2 + 26840);
  }
  if ( v1[2364] == 1 )
  {
    v1[2364] = 0;
    cancel_work_sync(&unk_6CE3B8);
    result = tasklet_kill(v2 + 26896);
  }
  if ( v1[2420] == 1 )
  {
    v1[2420] = 0;
    cancel_work_sync(&unk_6CE3F8);
    result = tasklet_kill(v2 + 26952);
  }
  if ( v1[2476] == 1 )
  {
    v1[2476] = 0;
    cancel_work_sync(&unk_6CE438);
    result = tasklet_kill(v2 + 27008);
  }
  if ( v1[2532] == 1 )
  {
    v1[2532] = 0;
    cancel_work_sync(&unk_6CE478);
    result = tasklet_kill(v2 + 27064);
  }
  *(_DWORD *)(v2 + 672) = 0;
  return result;
}
