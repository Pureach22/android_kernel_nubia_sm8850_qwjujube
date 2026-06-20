__int64 __fastcall rmnet_offload_deliver_descs(_QWORD *a1)
{
  __int64 result; // x0
  _QWORD *v3; // x21
  _QWORD *v4; // x20
  unsigned int v5; // w8
  __int64 v6; // x0
  _QWORD *v7; // x28
  _QWORD *v8; // x8
  __int64 v9; // x9

  result = rmnet_offload_state_get();
  v3 = (_QWORD *)*a1;
  if ( (_QWORD *)*a1 != a1 )
  {
    v4 = (_QWORD *)result;
    do
    {
      v5 = *((_DWORD *)v3 + 12);
      if ( v5 <= 0xC350 )
      {
        if ( v5 <= 0x7530 )
        {
          if ( v5 <= 0x59D8 )
          {
            if ( v5 <= 0x38A4 )
            {
              if ( v5 <= 0x1B58 )
              {
                if ( v5 <= 0x578 )
                  v6 = 21;
                else
                  v6 = 22;
              }
              else
              {
                v6 = 23;
              }
            }
            else
            {
              v6 = 24;
            }
          }
          else
          {
            v6 = 25;
          }
        }
        else
        {
          v6 = 26;
        }
      }
      else
      {
        v6 = 27;
      }
      v7 = (_QWORD *)*v3;
      rmnet_offload_stats_update(v6);
      rmnet_offload_stats_update(1);
      v8 = (_QWORD *)v3[1];
      if ( (_QWORD *)*v8 == v3 && (v9 = *v3, *(_QWORD **)(*v3 + 8LL) == v3) )
      {
        *(_QWORD *)(v9 + 8) = v8;
        *v8 = v9;
      }
      else
      {
        _list_del_entry_valid_or_report(v3);
      }
      *v3 = v3;
      v3[1] = v3;
      result = rmnet_frag_deliver(v3, *v4);
      v3 = v7;
    }
    while ( v7 != a1 );
  }
  return result;
}
