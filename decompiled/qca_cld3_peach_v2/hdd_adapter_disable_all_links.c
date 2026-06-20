__int64 __fastcall hdd_adapter_disable_all_links(__int64 result, char a2)
{
  __int64 v2; // x8
  __int64 v3; // x9
  __int64 v4; // x14
  __int64 v5; // x14
  int v6; // w9

  if ( !*(_DWORD *)(result + 40) )
  {
    v2 = result + 52840;
    if ( result && result != -52840 )
    {
      v3 = 0;
      while ( (unsigned __int64)(0x71B3F945A27B1F49LL * (v3 >> 3)) <= 2 )
      {
        if ( (a2 & 1) != 0 )
        {
          v4 = result + 52912 + v3;
          *(_WORD *)(v4 + 4) = 0;
          *(_DWORD *)v4 = 0;
        }
        v5 = 0x71B3F945A27B1F49LL * ((result + v3 - *(_QWORD *)(v2 + v3)) >> 3);
        if ( (unsigned __int8)(73 * ((result + v3 - *(_QWORD *)(v2 + v3)) >> 3)) > 2u )
        {
          __break(0x5512u);
          return hdd_open_adapter();
        }
        v3 += 6088;
        *(_BYTE *)(result + 1632 + (v5 & 3)) = v5;
        if ( !(v2 + v3) )
          break;
      }
    }
    v6 = -1 << *(_BYTE *)(result + 1648);
    *(_QWORD *)(result + 52832) = v2;
    *(_QWORD *)(result + 1640) = (unsigned int)~v6;
  }
  return result;
}
