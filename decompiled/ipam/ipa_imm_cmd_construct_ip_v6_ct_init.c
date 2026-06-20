__int64 __fastcall ipa_imm_cmd_construct_ip_v6_ct_init(unsigned int a1, __int64 a2, char a3)
{
  __int64 v5; // x1
  __int64 v6; // x21
  __int16 opcode; // w0
  __int64 v8; // x8
  char v9; // w9
  __int16 v10; // w11
  unsigned __int64 v11; // x8
  __int64 v12; // x9
  unsigned __int64 v13; // x8
  __int64 v14; // x10

  if ( (a3 & 1) != 0 )
    v5 = 2336;
  else
    v5 = 3520;
  v6 = _kmalloc_cache_noprof(of_property_read_variable_u32_array, v5, 28);
  if ( v6 )
  {
    opcode = ipahal_imm_cmd_get_opcode(a1);
    v8 = *(_QWORD *)(v6 + 20);
    v9 = *(_BYTE *)(a2 + 22);
    v10 = *(_WORD *)(a2 + 20);
    *(_WORD *)(v6 + 2) = opcode;
    v11 = v8 & 0xFFFFFFFFC00000C8LL | v9 & 7;
    v12 = *(unsigned __int8 *)(a2 + 16);
    *(_WORD *)v6 = 24;
    v13 = (v11 | (16 * v12) | (32LL * *(unsigned __int8 *)(a2 + 17))) & 0xFFFFFFFFFFF000FFLL
        | ((unsigned __int64)(*(_WORD *)(a2 + 18) & 0xFFF) << 8);
    v14 = *(_QWORD *)(a2 + 8);
    *(_QWORD *)(v6 + 4) = *(_QWORD *)a2;
    *(_QWORD *)(v6 + 12) = v14;
    *(_QWORD *)(v6 + 20) = v13 & 0xFFFFFFFFC00FFFFFLL | ((unsigned __int64)(v10 & 0x3FF) << 20);
  }
  return v6;
}
