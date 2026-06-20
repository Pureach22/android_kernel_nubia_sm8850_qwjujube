__int64 __fastcall rmnet_shs_wq_create_new_flow(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x0
  __int64 v3; // x1
  __int16 v4; // w8
  int v5; // w9
  __int64 v6; // x8
  __int64 v7; // x9

  if ( result )
  {
    v1 = result;
    result = rmnet_shs_wq_get_new_hstat_node();
    *(_QWORD *)(v1 + 88) = result;
    if ( result )
    {
      v2 = ktime_get_with_offset(1);
      result = ns_to_timespec64(v2);
      *(_DWORD *)(*(_QWORD *)(v1 + 88) + 300LL) = *(_DWORD *)(v1 + 192);
      *(_WORD *)(*(_QWORD *)(v1 + 88) + 320LL) = *(_WORD *)(v1 + 220);
      v4 = *(_WORD *)(v1 + 210);
      *(_WORD *)(*(_QWORD *)(v1 + 88) + 318LL) = v4;
      *(_WORD *)(*(_QWORD *)(v1 + 88) + 316LL) = v4;
      v5 = rmnet_shs_userspace_connected;
      *(_BYTE *)(*(_QWORD *)(v1 + 88) + 328LL) = 0;
      v6 = *(_QWORD *)(v1 + 88);
      if ( v5 )
      {
        if ( *(_WORD *)(v6 + 320) == 6 )
        {
          *(_BYTE *)(v6 + 328) = 2;
          v6 = *(_QWORD *)(v1 + 88);
        }
      }
      *(_QWORD *)(v6 + 88) = v1;
      v7 = v3 + 1000000000 * result;
      *(_QWORD *)(*(_QWORD *)(v1 + 88) + 112LL) = v7;
      *(_QWORD *)(*(_QWORD *)(v1 + 88) + 120LL) = v7;
    }
  }
  else
  {
    ++qword_1A448;
  }
  return result;
}
