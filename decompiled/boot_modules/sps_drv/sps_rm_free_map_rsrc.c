__int64 __fastcall sps_rm_free_map_rsrc(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x19

  if ( !*(_QWORD *)(result + 168) && !*(_QWORD *)(result + 176) )
  {
    v1 = result;
    if ( *(_DWORD *)(result + 188) != -1 )
    {
      sps_bam_pipe_free(*(_DWORD **)(result + 48), *(_DWORD *)(result + 32));
      result = v1;
      *(_DWORD *)(v1 + 188) = -1;
      *(_DWORD *)(v1 + 32) = -1;
    }
    if ( *(_DWORD *)(result + 192) != -1 )
    {
      sps_bam_pipe_free(*(_DWORD **)(result + 88), *(_DWORD *)(result + 72));
      result = v1;
      *(_DWORD *)(v1 + 192) = -1;
      *(_DWORD *)(v1 + 72) = -1;
    }
    if ( *(_QWORD *)(result + 200) != 3735928559LL )
    {
      sps_mem_free_io(*(_QWORD *)(result + 200), *(_DWORD *)(result + 120));
      result = v1;
      *(_QWORD *)(v1 + 200) = 3735928559LL;
      *(_QWORD *)(v1 + 104) = 3735928559LL;
    }
    if ( *(_QWORD *)(result + 208) != 3735928559LL )
    {
      v2 = result;
      result = sps_mem_free_io(*(_QWORD *)(result + 208), *(_DWORD *)(result + 152));
      *(_QWORD *)(v2 + 208) = 3735928559LL;
      *(_QWORD *)(v2 + 136) = 3735928559LL;
    }
  }
  return result;
}
