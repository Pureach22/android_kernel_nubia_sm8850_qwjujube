__int64 __fastcall msm_vidc_flush_read_only_buffers(__int64 a1, int a2)
{
  __int64 v3; // x21
  __int64 v4; // x24
  __int64 v5; // x20
  __int64 v6; // x25
  __int64 v7; // x9
  void (__fastcall *v8)(__int64, __int64); // x9
  __int64 v9; // x1
  __int64 v10; // x9
  void (__fastcall *v11)(_QWORD); // x9
  char v12; // w8
  __int64 v13; // x9
  void (__fastcall *v14)(__int64, __int64); // x9
  __int64 v15; // x1
  char v16; // w9
  __int64 *v17; // x8
  __int64 v18; // x9

  if ( a2 == 2 && *(_DWORD *)(a1 + 308) == 2 )
  {
    v3 = *(_QWORD *)(a1 + 2584);
    v4 = a1 + 2584;
    if ( v3 != a1 + 2584 )
    {
      v5 = *(_QWORD *)(a1 + 320);
      do
      {
        v6 = *(_QWORD *)v3;
        if ( (*(_BYTE *)(v3 + 80) & 2) == 0 )
        {
          print_vidc_buffer(1, (__int64)"high", (__int64)"flush ro buf", a1, v3);
          if ( *(_QWORD *)(v3 + 104) )
          {
            if ( !*(_QWORD *)(v3 + 96) )
              goto LABEL_37;
            if ( !v5 )
              goto LABEL_37;
            v7 = *(_QWORD *)(v5 + 6568);
            if ( !v7 )
              goto LABEL_37;
            v8 = *(void (__fastcall **)(__int64, __int64))(v7 + 48);
            if ( !v8 )
              goto LABEL_37;
            v9 = *(_QWORD *)(v3 + 104);
            if ( *((_DWORD *)v8 - 1) != -792689463 )
              __break(0x8229u);
            v8(v5, v9);
            if ( *(_QWORD *)(v3 + 104) )
            {
LABEL_37:
              if ( *(_QWORD *)(v3 + 88) )
              {
                if ( v5 )
                {
                  v10 = *(_QWORD *)(v5 + 6568);
                  if ( v10 )
                  {
                    v11 = *(void (__fastcall **)(_QWORD))(v10 + 32);
                    if ( v11 )
                    {
                      if ( *((_DWORD *)v11 - 1) != 248590048 )
                        __break(0x8229u);
                      v11(v5);
                    }
                  }
                }
              }
            }
          }
          v12 = *(_BYTE *)(v3 + 112);
          if ( (v12 & 1) != 0 )
          {
            if ( v5 )
            {
              v13 = *(_QWORD *)(v5 + 6568);
              if ( v13 )
              {
                v14 = *(void (__fastcall **)(__int64, __int64))(v13 + 8);
                if ( v14 )
                {
                  v15 = *(_QWORD *)(v3 + 88);
                  if ( *((_DWORD *)v14 - 1) != 381883841 )
                    __break(0x8229u);
                  v14(a1, v15);
                  v12 = *(_BYTE *)(v3 + 112);
                }
              }
            }
          }
          v16 = v12 & 0xFE;
          v17 = *(__int64 **)(v3 + 8);
          *(_QWORD *)(v3 + 96) = 0;
          *(_QWORD *)(v3 + 104) = 0;
          *(_QWORD *)(v3 + 88) = 0;
          *(_BYTE *)(v3 + 112) = v16;
          *(_QWORD *)(v3 + 56) = 0;
          if ( *v17 == v3 && (v18 = *(_QWORD *)v3, *(_QWORD *)(*(_QWORD *)v3 + 8LL) == v3) )
          {
            *(_QWORD *)(v18 + 8) = v17;
            *v17 = v18;
          }
          else
          {
            _list_del_entry_valid_or_report(v3);
          }
          *(_QWORD *)v3 = v3;
          *(_QWORD *)(v3 + 8) = v3;
          msm_vidc_pool_free(a1);
        }
        v3 = v6;
      }
      while ( v6 != v4 );
    }
  }
  return 0;
}
