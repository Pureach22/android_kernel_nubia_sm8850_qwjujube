__int64 __fastcall qdf_debugfs_hexdump(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  return seq_hex_dump(a1, &unk_98C763, 2, a4, a5, a2, a3, 0);
}
