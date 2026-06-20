__int64 ipa3_get_hw_type_index()
{
  __int64 result; // x0
  int v1; // w11
  unsigned int v2; // w10
  int v3; // w11
  unsigned int v4; // w9
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 v7; // x8

  result = 0;
  switch ( *(_DWORD *)(ipa3_ctx + 32240) )
  {
    case 0xA:
    case 0xB:
      return result;
    case 0xC:
      if ( *(_BYTE *)(ipa3_ctx + 32260) )
        return 2;
      else
        return 1;
    case 0xD:
      return 3;
    case 0xE:
      if ( *(_BYTE *)(ipa3_ctx + 32260) )
        return 5;
      else
        return 4;
    case 0xF:
      return 6;
    case 0x10:
      return 8;
    case 0x11:
      if ( *(_BYTE *)(ipa3_ctx + 32260) )
        v1 = 10;
      else
        v1 = 9;
      if ( *(_DWORD *)(ipa3_ctx + 32256) == 2 )
        v2 = 11;
      else
        v2 = v1;
      if ( *(_BYTE *)(ipa3_ctx + 32264) )
        v3 = 12;
      else
        v3 = v2;
      if ( *(_BYTE *)(ipa3_ctx + 32260) )
        v4 = 13;
      else
        v4 = v3;
      if ( *(_BYTE *)(ipa3_ctx + 32264) )
        return v4;
      else
        return v2;
    case 0x12:
      return 14;
    case 0x13:
      return 15;
    case 0x14:
      return 16;
    case 0x15:
      if ( *(_BYTE *)(ipa3_ctx + 32260) )
        return 18;
      else
        return 17;
    case 0x16:
      if ( *(_DWORD *)(ipa3_ctx + 32256) == 2 )
        return 20;
      else
        return 19;
    case 0x17:
      if ( *(_BYTE *)(ipa3_ctx + 48860) )
        return 22;
      else
        return 21;
    case 0x18:
      return 23;
    default:
      printk(&unk_3D397C, "ipa3_get_hw_type_index");
      v5 = ipa3_ctx;
      if ( !ipa3_ctx )
        return 0;
      v6 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v6 )
      {
        ipc_log_string(
          v6,
          "ipa %s:%d Incorrect IPA version %d\n",
          "ipa3_get_hw_type_index",
          7893,
          *(_DWORD *)(ipa3_ctx + 32240));
        v5 = ipa3_ctx;
      }
      v7 = v5 + 32240;
      result = *(_QWORD *)(v7 + 1920);
      if ( result )
      {
        ipc_log_string(result, "ipa %s:%d Incorrect IPA version %d\n", "ipa3_get_hw_type_index", 7893, *(_DWORD *)v7);
        return 0;
      }
      return result;
  }
}
