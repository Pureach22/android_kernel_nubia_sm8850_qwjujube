void *__fastcall drm_dp_sideband_append_payload(__int64 a1, const void *a2, unsigned __int8 a3)
{
  unsigned __int64 v3; // x8
  unsigned __int8 *v4; // x19
  void *result; // x0
  __int64 v7; // x20
  bool v8; // cc
  size_t v9; // x2

  if ( *(unsigned __int8 *)(a1 + 305) >= 0x31u )
    goto LABEL_9;
  v3 = *(unsigned __int8 *)(a1 + 305);
  v4 = (unsigned __int8 *)a1;
  if ( v3 > 0x30 )
    goto LABEL_9;
  result = memcpy((void *)(a1 + v3), a2, a3);
  v7 = v4[304];
  v8 = (unsigned int)v7 > (unsigned __int8)(v4[305] + a3);
  v4[305] += a3;
  if ( v8 )
    return result;
  a1 = drm_dp_msg_data_crc4((__int64)v4, (unsigned __int8)v7 - 1);
  v9 = v7 - 1;
  if ( (unsigned __int64)(v7 - 1) > 0x2F )
  {
LABEL_9:
    __break(0x5512u);
    return (void *)drm_dp_check_and_send_link_address(a1, a2);
  }
  if ( v4[v9] != (unsigned __int8)a1 )
  {
    print_hex_dump(&unk_1C719, "wrong crc", 0, 16, 1, v4, v7, 0);
    v9 = v4[304] - 1LL;
  }
  result = memcpy(&v4[v4[307] + 48], v4, v9);
  v4[307] = v4[304] + v4[307] - 1;
  return result;
}
