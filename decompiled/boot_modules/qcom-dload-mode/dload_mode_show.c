__int64 __fastcall dload_mode_show(__int64 a1, __int64 a2, __int64 a3)
{
  const char *v3; // x3

  switch ( dump_mode )
  {
    case 16:
      v3 = "full";
      break;
    case 48:
      v3 = "both";
      break;
    case 32:
      v3 = "mini";
      break;
    default:
      v3 = "unknown";
      break;
  }
  return (int)scnprintf(a3, 4096, "DLOAD dump type: %s\n", v3);
}
