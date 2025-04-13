from PIL import Image
import struct

def bmp_to_rgb565(new_bmp, output_file):
    # Open the BMP image
    img = Image.open(new_bmp).convert('RGB')
    width, height = img.size

    # Create and write RGB565 data
    with open(output_file, 'wb') as f:
        for y in range(height):
            for x in range(width):
                r, g, b = img.getpixel((x, y))
                # Convert RGB888 to RGB565
                rgb565 = ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3)
                f.write(struct.pack('>H', rgb565))  # Big-endian 16-bit

    print(f"Conversion complete: {output_file}")

# Example usage
bmp_to_rgb565('image.bmp', 'image.rgb565')
