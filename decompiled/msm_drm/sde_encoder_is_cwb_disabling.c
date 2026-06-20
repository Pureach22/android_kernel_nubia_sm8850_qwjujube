__int64 __fastcall sde_encoder_is_cwb_disabling(__int64 result, __int64 a2)
{
  int v2; // w8
  __int64 v3; // x9
  __int64 v4; // x9
  __int64 v5; // x9
  __int64 v6; // x9

  if ( result )
  {
    if ( *(_DWORD *)(result + 640) == 15 && *(_QWORD *)(result + 1360) == a2 )
    {
      v2 = *(_DWORD *)(result + 196);
      if ( v2 )
      {
        v3 = *(_QWORD *)(result + 200);
        if ( v3 && *(_BYTE *)(v3 + 2290) == 1 && !*(_DWORD *)(v3 + 832) && *(_QWORD *)(v3 + 2936) == a2 )
          return 1;
        if ( v2 != 1 )
        {
          v4 = *(_QWORD *)(result + 208);
          if ( v4 && *(_BYTE *)(v4 + 2290) == 1 && !*(_DWORD *)(v4 + 832) && *(_QWORD *)(v4 + 2936) == a2 )
            return 1;
          if ( v2 != 2 )
          {
            v5 = *(_QWORD *)(result + 216);
            if ( v5 && *(_BYTE *)(v5 + 2290) == 1 && !*(_DWORD *)(v5 + 832) && *(_QWORD *)(v5 + 2936) == a2 )
              return 1;
            if ( v2 != 3 )
            {
              v6 = *(_QWORD *)(result + 224);
              if ( v6 && *(_BYTE *)(v6 + 2290) == 1 && !*(_DWORD *)(v6 + 832) && *(_QWORD *)(v6 + 2936) == a2 )
                return 1;
              if ( v2 != 4 )
              {
                __break(0x5512u);
                return 1;
              }
            }
          }
        }
      }
    }
    return 0;
  }
  return result;
}
