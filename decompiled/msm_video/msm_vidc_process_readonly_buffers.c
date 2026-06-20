__int64 __fastcall msm_vidc_process_readonly_buffers(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  __int64 *v3; // x24
  __int64 v4; // x20
  __int64 *v6; // x8
  __int64 *v7; // x10
  __int64 *v8; // x25
  __int64 v9; // x8
  void (__fastcall *v10)(_QWORD); // x9
  void (__fastcall *v11)(__int64, __int64, __int64); // x8
  __int64 v12; // x1
  __int64 v13; // x2
  char v14; // w8
  __int64 v15; // x9
  void (__fastcall *v16)(__int64, __int64); // x9
  __int64 v17; // x1
  __int64 **v18; // x8
  __int64 *v19; // x9

  if ( *(_DWORD *)(a1 + 308) == 2 && *(_DWORD *)(a2 + 24) == 2 )
  {
    v2 = *(_QWORD *)(a1 + 2584);
    v3 = (__int64 *)(a1 + 2584);
    v4 = *(_QWORD *)(a1 + 320);
    if ( v2 != a1 + 2584 )
    {
      v6 = *(__int64 **)(a1 + 2584);
      while ( 1 )
      {
        v7 = (__int64 *)*v6;
        if ( v6[7] == *(_QWORD *)(a2 + 56) && (v6[10] & 6) == 2 )
          break;
        v6 = (__int64 *)*v6;
        if ( v7 == v3 )
          goto LABEL_9;
      }
      *(_DWORD *)(a2 + 80) |= 2u;
      *((_DWORD *)v6 + 20) &= ~2u;
      v2 = *v3;
    }
LABEL_9:
    if ( (__int64 *)v2 != v3 )
    {
      do
      {
        v8 = *(__int64 **)v2;
        if ( (*(_BYTE *)(v2 + 80) & 2) == 0 )
        {
          print_vidc_buffer(4, (__int64)"low ", (__int64)"ro buf removed", a1, v2);
          if ( *(_QWORD *)(v2 + 96) && *(_QWORD *)(v2 + 104) )
          {
            if ( v4 )
            {
              v9 = *(_QWORD *)(v4 + 6568);
              if ( v9 )
              {
                v10 = *(void (__fastcall **)(_QWORD))(v9 + 48);
                if ( !v10 )
                  goto LABEL_23;
                if ( *((_DWORD *)v10 - 1) != -792689463 )
                  __break(0x8229u);
                v10(v4);
                v9 = *(_QWORD *)(v4 + 6568);
                if ( v9 )
                {
LABEL_23:
                  v11 = *(void (__fastcall **)(__int64, __int64, __int64))(v9 + 32);
                  if ( v11 )
                  {
                    v12 = *(_QWORD *)(v2 + 88);
                    v13 = *(_QWORD *)(v2 + 104);
                    if ( *((_DWORD *)v11 - 1) != 248590048 )
                      __break(0x8228u);
                    v11(v4, v12, v13);
                  }
                }
              }
            }
            *(_QWORD *)(v2 + 96) = 0;
            *(_QWORD *)(v2 + 104) = 0;
          }
          v14 = *(_BYTE *)(v2 + 112);
          if ( (v14 & 1) != 0 )
          {
            if ( v4 )
            {
              v15 = *(_QWORD *)(v4 + 6568);
              if ( v15 )
              {
                v16 = *(void (__fastcall **)(__int64, __int64))(v15 + 8);
                if ( v16 )
                {
                  v17 = *(_QWORD *)(v2 + 88);
                  if ( *((_DWORD *)v16 - 1) != 381883841 )
                    __break(0x8229u);
                  v16(a1, v17);
                  v14 = *(_BYTE *)(v2 + 112);
                }
              }
            }
            *(_QWORD *)(v2 + 88) = 0;
            *(_BYTE *)(v2 + 112) = v14 & 0xFE;
          }
          v18 = *(__int64 ***)(v2 + 8);
          if ( *v18 == (__int64 *)v2 && (v19 = *(__int64 **)v2, *(_QWORD *)(*(_QWORD *)v2 + 8LL) == v2) )
          {
            v19[1] = (__int64)v18;
            *v18 = v19;
          }
          else
          {
            _list_del_entry_valid_or_report(v2);
          }
          *(_QWORD *)v2 = v2;
          *(_QWORD *)(v2 + 8) = v2;
          msm_vidc_pool_free(a1);
        }
        v2 = (__int64)v8;
      }
      while ( v8 != v3 );
    }
  }
  return 0;
}
