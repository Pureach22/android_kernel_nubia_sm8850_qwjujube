__int64 __fastcall ipa3_get_prot_id(int a1)
{
  int v1; // w9
  __int64 result; // x0
  int v4; // w19
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 v7; // x0

  v1 = a1 - 10;
  result = 1;
  switch ( v1 )
  {
    case 0:
    case 1:
      result = 3;
      break;
    case 2:
    case 3:
    case 109:
      result = 4;
      break;
    case 8:
    case 9:
      result = 7;
      break;
    case 38:
    case 39:
    case 106:
    case 107:
      result = 5;
      break;
    case 76:
    case 77:
    case 79:
    case 81:
    case 83:
      result = 2;
      break;
    case 86:
    case 87:
    case 88:
    case 89:
      result = 6;
      break;
    case 92:
    case 93:
      return result;
    case 98:
    case 99:
      result = 9;
      break;
    default:
      v4 = a1;
      printk(&unk_3DC2E9, "ipa3_get_prot_id");
      v5 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v6 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v6 )
        {
          ipc_log_string(v6, "ipa %s:%d unknown prot_id for client %d\n", "ipa3_get_prot_id", 14045, v4);
          v5 = ipa3_ctx;
        }
        v7 = *(_QWORD *)(v5 + 34160);
        if ( v7 )
          ipc_log_string(v7, "ipa %s:%d unknown prot_id for client %d\n", "ipa3_get_prot_id", 14045, v4);
      }
      result = 4294967274LL;
      break;
  }
  return result;
}
