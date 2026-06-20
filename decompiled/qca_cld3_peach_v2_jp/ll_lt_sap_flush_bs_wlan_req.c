__int64 __fastcall ll_lt_sap_flush_bs_wlan_req(__int64 result)
{
  __int64 i; // x8
  __int64 v2; // x9
  __int64 v3; // x11
  __int64 v4; // x10
  __int64 v5; // x12
  int v6; // w11
  int v7; // w13

  if ( !*(_QWORD *)(result + 272) || *(_DWORD *)(result + 264) == 1 )
  {
    *(_QWORD *)(result + 272) = 0;
    *(_QWORD *)(result + 288) = 0;
    *(_DWORD *)(result + 280) = 0;
  }
  if ( !*(_QWORD *)(result + 312) || *(_DWORD *)(result + 304) == 1 )
  {
    *(_QWORD *)(result + 312) = 0;
    *(_QWORD *)(result + 328) = 0;
    *(_DWORD *)(result + 320) = 0;
  }
  if ( !*(_QWORD *)(result + 352) || *(_DWORD *)(result + 344) == 1 )
  {
    *(_QWORD *)(result + 352) = 0;
    *(_QWORD *)(result + 368) = 0;
    *(_DWORD *)(result + 360) = 0;
  }
  if ( !*(_QWORD *)(result + 392) || *(_DWORD *)(result + 384) == 1 )
  {
    *(_QWORD *)(result + 392) = 0;
    *(_QWORD *)(result + 408) = 0;
    *(_DWORD *)(result + 400) = 0;
  }
  if ( !*(_QWORD *)(result + 432) || *(_DWORD *)(result + 424) == 1 )
  {
    *(_QWORD *)(result + 432) = 0;
    *(_QWORD *)(result + 448) = 0;
    *(_DWORD *)(result + 440) = 0;
  }
  for ( i = 0; i != 200; i += 40 )
  {
    if ( i )
    {
      v2 = result + i;
      v3 = *(_QWORD *)(result + i + 272);
      if ( v3 )
      {
        v4 = result + i;
        if ( *(_QWORD *)(result + 272) )
        {
          if ( i == 40 )
            continue;
        }
        else
        {
          v5 = *(_QWORD *)(v4 + 288);
          *(_QWORD *)(result + 272) = v3;
          *(_QWORD *)(result + 288) = v5;
          LODWORD(v5) = *(_DWORD *)(v4 + 280);
          *(_QWORD *)(v4 + 288) = 0;
          *(_DWORD *)(result + 280) = v5;
          v6 = *(_DWORD *)(v4 + 264);
          LODWORD(v5) = *(_DWORD *)(v4 + 268);
          *(_QWORD *)(v2 + 272) = 0;
          *(_DWORD *)(v4 + 280) = 0;
          *(_DWORD *)(result + 264) = v6;
          LOBYTE(v6) = *(_BYTE *)(v2 + 256);
          v7 = *(_DWORD *)(v4 + 260);
          *(_DWORD *)(result + 268) = v5;
          *(_BYTE *)(result + 256) = v6;
          v3 = 0;
          *(_DWORD *)(result + 260) = v7;
          if ( i == 40 )
            continue;
        }
        if ( *(_QWORD *)(result + 312) )
        {
          if ( i == 80 )
            continue;
        }
        else
        {
          *(_QWORD *)(result + 312) = v3;
          v3 = 0;
          *(_QWORD *)(result + 328) = *(_QWORD *)(v4 + 288);
          *(_DWORD *)(result + 320) = *(_DWORD *)(v4 + 280);
          *(_DWORD *)(result + 304) = *(_DWORD *)(v4 + 264);
          *(_BYTE *)(result + 296) = *(_BYTE *)(v2 + 256);
          *(_DWORD *)(result + 300) = *(_DWORD *)(v4 + 260);
          *(_DWORD *)(result + 308) = *(_DWORD *)(v4 + 268);
          *(_QWORD *)(v2 + 272) = 0;
          *(_QWORD *)(v4 + 288) = 0;
          *(_DWORD *)(v4 + 280) = 0;
          if ( i == 80 )
            continue;
        }
        if ( *(_QWORD *)(result + 352) )
        {
          if ( i == 120 )
            continue;
        }
        else
        {
          *(_QWORD *)(result + 352) = v3;
          v3 = 0;
          *(_QWORD *)(result + 368) = *(_QWORD *)(v4 + 288);
          *(_DWORD *)(result + 360) = *(_DWORD *)(v4 + 280);
          *(_DWORD *)(result + 344) = *(_DWORD *)(v4 + 264);
          *(_BYTE *)(result + 336) = *(_BYTE *)(v2 + 256);
          *(_DWORD *)(result + 340) = *(_DWORD *)(v4 + 260);
          *(_DWORD *)(result + 348) = *(_DWORD *)(v4 + 268);
          *(_QWORD *)(v2 + 272) = 0;
          *(_QWORD *)(v4 + 288) = 0;
          *(_DWORD *)(v4 + 280) = 0;
          if ( i == 120 )
            continue;
        }
        if ( !*(_QWORD *)(result + 392) )
        {
          *(_QWORD *)(result + 392) = v3;
          *(_QWORD *)(result + 408) = *(_QWORD *)(v4 + 288);
          *(_DWORD *)(result + 400) = *(_DWORD *)(v4 + 280);
          *(_DWORD *)(result + 384) = *(_DWORD *)(v4 + 264);
          *(_BYTE *)(result + 376) = *(_BYTE *)(v2 + 256);
          *(_DWORD *)(result + 380) = *(_DWORD *)(v4 + 260);
          *(_DWORD *)(result + 388) = *(_DWORD *)(v4 + 268);
          *(_QWORD *)(v2 + 272) = 0;
          *(_QWORD *)(v4 + 288) = 0;
          *(_DWORD *)(v4 + 280) = 0;
        }
      }
    }
  }
  return result;
}
