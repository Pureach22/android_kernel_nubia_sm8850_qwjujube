__int64 __fastcall hfi_create_packet_header(__int64 a1, _DWORD *a2)
{
  _DWORD *v2; // x8
  unsigned int v3; // w2
  __int64 v4; // x9
  char *v5; // x9
  __int64 result; // x0
  int v7; // w10

  if ( a1 && a2 && (v2 = *(_DWORD **)a1) != nullptr )
  {
    v3 = *(_DWORD *)(a1 + 8);
    if ( v3 <= 0x1F )
    {
      printk(&unk_261BBB, "hfi_validate_cmd_buff_size");
      return 0xFFFFFFFFLL;
    }
    else
    {
      v4 = *v2 & 0xFFFFFF;
      if ( (int)v4 + 32 > v3 )
      {
        printk(&unk_27684F, "hfi_validate_cmd_buff_size");
        return 0xFFFFFFFFLL;
      }
      else
      {
        v5 = (char *)v2 + v4;
        result = 0;
        *((_QWORD *)v5 + 2) = 0;
        *((_QWORD *)v5 + 3) = 0;
        *(_QWORD *)v5 = 0;
        *((_QWORD *)v5 + 1) = 0;
        *(_DWORD *)v5 = (a2[4] << 21) | 0x20;
        *((_DWORD *)v5 + 1) = *a2;
        *((_DWORD *)v5 + 2) = a2[2];
        *((_DWORD *)v5 + 3) = a2[1];
        *((_DWORD *)v5 + 4) = a2[3];
        v7 = v2[7];
        *v2 += 32;
        v2[7] = v7 + 1;
      }
    }
  }
  else
  {
    printk(&unk_265327, "hfi_create_packet_header");
    return 0xFFFFFFFFLL;
  }
  return result;
}
